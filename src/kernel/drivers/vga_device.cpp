#include <drivers/vga_device.h>

VGA_Device * VGA_Device::instance_ = nullptr;

VGA_Device::VGA_Device(unsigned short * buffer_location)
{
    buffer_ = buffer_location;
    coursor_x_ = 0;
    coursor_y_ = 0;
    text_color_ = VGA_COLOR_GREEN;
	background_ = VGA_COLOR_BLACK;
}

VGA_Device::~VGA_Device()
{

}

VGA_Device * VGA_Device::Instance()
{
    if (instance_ == nullptr)
    {
        instance_ = new VGA_Device((unsigned short *)0xB8000);
    }
    return instance_;
}

void VGA_Device::enable_cursor(unsigned short cursor_start, unsigned short cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void VGA_Device::update_cursor(int x, int y)
{
	uint16_t pos = (x* vga_width) + y;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

//blends the char with the color bits that are needed for vga
unsigned short VGA_Device::format_char_data(char c)
{
    uint8_t colors = (background_ << 4) | text_color_;

    uint16_t colored_char = ((uint16_t) colors << 8 | (uint16_t) c); 
    return colored_char;
}

void VGA_Device::set_color(char text, char background)
{
    text_color_ = text;
    background_ = background;
}

//places a single character at the specified location
void VGA_Device::place_char_at_location(char c, size_t x, size_t y)
{
    buffer_[(x * vga_width) + y] = format_char_data(c); //put the char at the location
}

void VGA_Device::scroll_screen() //TODO: use memcpy
{
    uint32_t max = vga_height * vga_width;

    for (uint16_t i = vga_width+1; i<max; i++)
    {
        buffer_[i-vga_width] = buffer_[i];
    }

    for (uint16_t i = 0; i < vga_width; i++)
    {
        place_char_at_location(' ', vga_height-1, i);
    }
    //coursor_x-=1;
}

//prints a single char to the screen, and keeps track of when 
//there needs to be a carrage return
void VGA_Device::put_char(const char * c)
{
    if ((coursor_y_ > vga_width-1) || (*c == '\n'))
    {
        if (coursor_x_ >= vga_height-1)
        {
            scroll_screen();
        }
        else
        {
            coursor_x_++;

        }
        coursor_y_=0;
        if (*c != '\n')
        {
            place_char_at_location(*c,coursor_x_, coursor_y_);
        }
    }
    else if (coursor_x_ > vga_height-1)
    {
        scroll_screen();
        place_char_at_location(*c,coursor_x_, coursor_y_);
    }
    else
    {
        place_char_at_location(*c,coursor_x_, coursor_y_);
    }
    
    coursor_y_++;
    update_cursor(coursor_x_,coursor_y_);
}

//goes through the entire screen and puts in blank spaces
void VGA_Device::clear_screen()
{
    enable_cursor(0,25);
    update_cursor(0,0);
    for (size_t i = 0; i < vga_width; i++)
    {
        for (size_t j = 0; j < vga_height; j++)
        {
            place_char_at_location(' ', j, i);
        }
    }
    coursor_x_ = 0;
    coursor_y_ = 0;
}

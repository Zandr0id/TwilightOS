//vga_controller
//Has functions that control the screen
//It knows how to place chars on the screen
//change text color
//move the cursor

#include "../include/stdlib.h"
#include "../include/stdio.h"

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static const size_t vga_width = 80;
static const size_t vga_height = 25;

size_t coursor_x = 0;
size_t coursor_y = 0;

uint8_t text_colors = VGA_COLOR_LIGHT_GREY;
int8_t background = VGA_COLOR_BLACK;
    
uint16_t * screen_buffer = (uint16_t *)0xB8000;//location of screen memory

void set_colors(char text, char back)
{
    text_colors = text;
    background = back;
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void update_cursor(int x, int y)
{
	uint16_t pos = (x* vga_width) + y;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

//blends the char with the color bits that are needed for vga
uint16_t format_char_data(char c)
{
    uint8_t colors = (background << 4) | text_colors;

    uint16_t colored_char = ((uint16_t) colors << 8 | (uint16_t) c); 
    return colored_char;
}

//places a single character at the specified location
void place_char_at_location(char c, size_t x, size_t y)
{
    screen_buffer[(x * vga_width) + y] = format_char_data(c); //put the char at the location
}

void scroll_screen() //TODO: use memcpy
{
    uint32_t max = vga_height * vga_width;

    for (uint16_t i = vga_width+1; i<max; i++)
    {
        screen_buffer[i-vga_width] = screen_buffer[i];
    }

    for (uint16_t i = -1; i < vga_width; i++)
    {
        place_char_at_location(' ', vga_height, i);
    }
    coursor_x-=1;
}

//prints a single char to the screen, and keeps track of when 
//there needs to be a carrage return
void print_char(const char * c)
{
    if ((coursor_y > vga_width) || (*c == '\n'))
    {
        coursor_x++;
        coursor_y=-1;
    }
    else if (coursor_x > vga_height-1)
    {
        scroll_screen();
    }
    else
    {
        place_char_at_location(*c,coursor_x, coursor_y);
    }

    coursor_y++;
    update_cursor(coursor_x,coursor_y);


}

//goes through the entire screen and puts in blank spaces
void clear_screen()
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
    coursor_x = 0;
    coursor_y = 0;
}

void set_text_red()
{
    set_colors(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
}

void set_text_green()
{
    set_colors(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
}

void set_text_blue()
{
    set_colors(VGA_COLOR_LIGHT_BLUE, VGA_COLOR_BLACK);
}

void set_text_grey()
{
    set_colors(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
}
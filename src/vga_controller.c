//vga_controller
//Has functions that control the screen
//It knows how to place chars on the screen
//change text color
//move the cursor

#include "stdlib.h"

enum color_options
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    PINK = 13,
    YELLOW = 14,
    WHITE = 15,
};

size_t vga_width = 80;
size_t vga_height = 25;
uint16_t * screen_buffer = (uint16_t *) 0xB8000; //location of screen memory

size_t coursor_x = 0;
size_t coursor_y = 0;

uint8_t text_colors = LIGHT_GREY;
uint8_t background = BLACK;

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

//prints a single char to the screen, and keeps track of when 
//there needs to be a carrage return
void print_char(const char * c)
{
    if ((coursor_x > vga_width) || (*c == '\n'))
    {
        carraige_return();
    }
    else
    {
        place_char_at_location(*c,coursor_x, coursor_y);
    }
    coursor_y++;
    update_cursor(coursor_x,coursor_y);
}

//moves the cursor back to the left, and down one row.
void carraige_return()
{
    coursor_x++;
    coursor_y = 0;
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

//just prints strings to the screen memory in white on black
//pehaps add changing colors later

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

uint8_t text_colors = PINK;
uint8_t background = BLACK;

void set_colors(char text, char back)
{
    text_colors = text;
    background = back;
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

void print_char(const char * c)
{
    if ((coursor_x > vga_width) || (*c == '\n'))
    {
        coursor_x++;
        coursor_y = 0;
    }
    else if(*c == '\t')
    {
        for (char p=0;p<5;p++) // just do 5 spaces for a tab
        {
            print_char(" "); //a recursive call here!!!
        }

    }
    else
    {
        place_char_at_location(*c,coursor_x, coursor_y);
        coursor_y++;
    }
    
   
}

//prints the string at the current location
//also handles new-lines and tabs
void print_line(const char* data)
{
    for (int i=0; i < strlen(data); i++)
    {
        if ((coursor_x > vga_width) || (data[i] == '\n'))
        {
            coursor_x++;
            coursor_y = 0;
            continue;
        }
        else if(data[i] == '\t')
        {
            for (char p=0;p<5;p++) // just do 5 spaces for a tab
            {
                print_char(" "); //a recursive call here!!!
            }
            continue;
        }
        else
        {
            place_char_at_location(data[i],coursor_x, coursor_y);
            coursor_y++;
        }
    }
}

//goes through the entire screen and puts a blank space in
void clear_screen()
{
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

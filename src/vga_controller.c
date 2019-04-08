//just prints strings to the screen memory in white on black
//pehaps add changing colors later

#include "vga_controller.h"

size_t vga_width = 80;
size_t vga_height = 25;
uint16_t * screen_buffer = (uint16_t *) 0xB8000; //location of screen memory

size_t coursor_x = 0;
size_t coursor_y = 0;

uint8_t text_colors = 10; //green
uint8_t background = 0; //black

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


//returns the length of the string
size_t strlen(const char* data)
{
    size_t len = 0;
    while(data[len])
    {
        len++;
    }
    return len;
}

//prints the string at the current location
//also handles new-lines and tabs
void print_text(const char* data)
{
    for (size_t i=0; i < strlen(data); i++)
    {
        
        if ((coursor_x > vga_width) || (data[i] == '\n'))
        {
            coursor_x++;
            coursor_y = 0;
            continue;
        }
        if(data[i] == '\t')
        {
            print_text("     "); //a recursive call here!!!
            continue;
        }
        place_char_at_location(data[i],coursor_x, coursor_y);
        coursor_y++;
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

//prints in green
void print_good(const char* data)
{
     set_colors(10,0); //green on black
     print_text(data);
}

//prints in red
void print_bad(const char* data)
{
     set_colors(4,0); //red on black
     print_text(data);
}

//prints in grey
void print(const char* data)
{
    set_colors(7,0); //grey on black
    print_text(data);
}
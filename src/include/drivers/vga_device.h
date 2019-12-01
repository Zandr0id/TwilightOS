#ifndef VGA_DEVICE_H_
#define VGA_DEVICE_H_

#include <libc/stdlib.h>
#include <libc/stdio.h>
#include <libc/memory.h>

 enum vga_color
{
	VGA_COLOR_BLACK,
	VGA_COLOR_BLUE,
	VGA_COLOR_GREEN,
	VGA_COLOR_CYAN,
	VGA_COLOR_RED,
	VGA_COLOR_MAGENTA,
	VGA_COLOR_BROWN,
	VGA_COLOR_LIGHT_GREY,
	VGA_COLOR_DARK_GREY,
	VGA_COLOR_LIGHT_BLUE,
	VGA_COLOR_LIGHT_GREEN,
	VGA_COLOR_LIGHT_CYAN,
	VGA_COLOR_LIGHT_RED,
	VGA_COLOR_LIGHT_MAGENTA,
	VGA_COLOR_LIGHT_BROWN,
	VGA_COLOR_WHITE
};


static const size_t vga_width = 80;
static const size_t vga_height = 25;

class VGA_Device
{
public:
    static VGA_Device * Instance();
    void put_char(const char * c);
    void set_color(char text, char background);
    void clear_screen();
private:
    VGA_Device(unsigned short * buffer_location);
    ~VGA_Device();
    size_t coursor_x_;
    size_t coursor_y_;
	char text_color_;
	char background_;
	static VGA_Device * instance_;
    unsigned short * buffer_; // the location of screen memory
    void enable_cursor(unsigned short cursor_start, unsigned short cursor_end);
    void update_cursor(int x, int y);
    unsigned short format_char_data(char c);
    void place_char_at_location(char c, size_t x, size_t y);
    void scroll_screen();
};

#endif //VGA_DEVICE_H_
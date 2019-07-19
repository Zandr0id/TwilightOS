//this is standard lib!
// This H file will be included into the kernel, and all other files will be liked into this one.

#ifndef STDLIB_H
#define STDLIB_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

// screen related functions
extern void clear_screen();
extern void print_line(const char* data);
extern void print_char(const char * c);


//memory related functions
extern unsigned char* memcpy(unsigned char* dest, unsigned char* src, int count);
extern unsigned char* memset(unsigned char* dest, unsigned char val, int count);
extern unsigned short* memsetw(unsigned char* dest, unsigned short val, int count);
extern int strlen(const char* data);

//I/O related functions
extern void printf(const char * format, ...);
char* convert(unsigned int num, int base); //Convert integer number into octal, hex, etc.
#endif //STDLIB_H
//this is standard lib!
// This H file will be included into the kernel, and all other files will be liked into this one.

#ifndef STDLIB_H
#define STDLIB_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// screen related functions
extern void clear_screen();
extern void print(const char* data);
extern void print_good(const char* data);
extern void print_bad(const char* data);

//memory related functions
extern unsigned char* memcpy(unsigned char* dest, unsigned char* src, int count);
extern unsigned char* memset(unsigned char* dest, unsigned char val, int count);
extern unsigned short* memsetw(unsigned char* dest, unsigned short val, int count);
extern void hex_string(unsigned int num, char* ret);
extern int strlen(const char* data);

//I/O related functions

#endif //STDLIB_H
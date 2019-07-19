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
extern void print_char(const char * c);
extern void carraige_return();

//memory related functions
extern unsigned char* memcpy(unsigned char* dest, unsigned char* src, int count);
extern unsigned char* memset(unsigned char* dest, unsigned char val, int count);
extern unsigned short* memsetw(unsigned char* dest, unsigned short val, int count);
extern int strlen(const char* data);

//I/O related functions
extern void printf(const char * format, ...); // The good ol' printf function
char* convert(unsigned int num, int base); //Convert integer number into octal, hex, etc.

//These must be defined here to avoid compiler warnings
//It wasn't liking me trying to use Extern Inline as a function signature, and have it defined somewhere else
//Just having them in the .h file solved it
inline void outb(uint16_t port, uint8_t val)
{
    __asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port) );
}

inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

#endif //STDLIB_H
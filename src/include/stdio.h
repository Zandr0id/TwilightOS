/*
stdio.h
This header contains prototypes for functions that deal with I/o related stuff
Written by Zane Youmans
10/16/19
*/

#ifndef STDIO_H_
#define STDIO_H_

#include "basics.h"

//I/O related functions

extern void printf(const char * format, ...); // The good ol' printf function
extern void print_char(const char * c);//print a single char to the next location in the screen
extern void write_serial_string(const char *c);
extern void write_char_serial(char c);

//These must be defined here to avoid compiler warnings
//It wasn't liking me trying to use Extern Inline as a function signature, and have it defined somewhere else
//Just having them in the .h file solved it
inline void outb(uint16_t port, uint8_t val) // write a value to a port
{
    __asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port) );
}

inline uint8_t inb(uint16_t port) //read a value from a port
{
    uint8_t ret;
    __asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}
#endif //STDIO_H_
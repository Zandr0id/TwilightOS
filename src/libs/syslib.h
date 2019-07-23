//this is syslib
//it's just stuff that the kernel can use

#ifndef SYSLIB_H
#define SYSLIB_H

#include "basiclib.h"

// screen related functions
extern void clear_screen(); //whipe out the screen
extern void print_char(const char * c);//print a single char to the next location in the screen
extern void carraige_return(); //move down one row
extern void set_colors(char text, char back);
extern void set_text_grey();
extern void set_text_blue();
extern void set_text_green();
extern void set_text_red();

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


// descriptor table functions
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();
extern void isr_install();

struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp ,ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};




#endif
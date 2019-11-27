/*
syslib.h
These are system level functions meant to be used by the kernel
Written by Zane Youmans
10/16/19
*/

#ifndef SYSLIB_H
#define SYSLIB_H

#include <basics.h>

// screen related functions
extern void clear_screen(); //whipe out the screen

extern void set_colors(char text, char back);
extern void set_text_grey();
extern void set_text_blue();
extern void set_text_green();
extern void set_text_red();

// system installation functions
extern void gdt_add_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();
extern void idt_add_entry(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();
extern void isr_install();
extern void time_install(int freq);
extern void PIC_install();
extern void keyboard_install();
extern void paging_install();

//beginning of syscalls?
extern unsigned int get_system_uptime();
extern char get_last_character();

struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp ,ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};

#endif //SYSLIB_H_
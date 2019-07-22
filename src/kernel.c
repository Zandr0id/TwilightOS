

/* Check if the compiler thinks you are targeting the wrong operating system. 
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif*/
 
/* This tutorial will only work for the 32-bit ix86 targets. 
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif*/
 
#include "stdlib.h"

//extern "C" 
void kernel_main(void) 
{
	gdt_install();
	idt_install();
	isr_install();

	clear_screen();
	set_text_green();
	printf("Int: %d \nChar: %c \nHex: %x \nOct: %o \nStr: %s \n\0",-85,"R",255,128,"Hello");

	set_text_red();
	printf("HI There\n\0");

	int test = 5/0;
	printf("%i",test);

}
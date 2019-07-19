

/* Check if the compiler thinks you are targeting the wrong operating system. 
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif*/
 
/* This tutorial will only work for the 32-bit ix86 targets. 
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif*/
 
 #include "stdlib.h"

void kernel_main(void) 
{

	 //print mem 
	unsigned int * mem1 = (unsigned int *)0xA5000;
	*mem1=0x1;
	unsigned int * mem2 = (unsigned int *) 0xA6000;
	*mem2=0x3;

	clear_screen();
	printf("Int: %d\nChar: %c\nHex: %x\nOct: %o\nStr: %s\0",-85,"R",255,128,"Hello");
}
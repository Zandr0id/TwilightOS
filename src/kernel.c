

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
	clear_screen();
 
	print_good("Kernel has booted!\n");
	print_bad("This would be an error....\n");
	char eh[10];
	hex_string(0xFFFFFFFF,eh);
	print(eh);
}
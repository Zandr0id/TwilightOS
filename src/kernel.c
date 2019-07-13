

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
 	
	int * mem = (int*) 0xA5983;
	*mem=0xFF88FF;
	hex_string(*mem);
	print("\n");

	int count = 1;
	unsigned char value = 0xFF;
	unsigned char * loc = (unsigned char *) 0xC1000;

	hex_string((unsigned int) memset(loc, value, count));
	print("\n");
	hex_string(*loc);
	print("\n");

	print_good("Kernel has booted!\n\0");
	print_bad("This would be an error....\n\0");

}
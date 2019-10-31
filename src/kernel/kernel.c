/*
	This is the kernel main! This is the entry point into the system
	It calls all the functions needed for the initial processor setup
*/

#include "../include/stdlib.h"
#include "../include/stdio.h"
#include "../include/syslib.h"

//#define INSTA_FAIL

//extern "C" 
void kernel_main(void) 
{
	clear_screen();

	set_text_red();
    printf("  ____ _            ___  ____\n\0"); 
	printf(" / ___| |__   __ _ / _ \\/ ___|\n\0");
	printf("| |   | '_ \\ / _` | | | \\___ \\\n\0"); 
	printf("| |___| | | | (_| | |_| |___) |\n\0");
	printf(" \\____|_| |_|\\__,_|\\___/|____/\n\0");
	printf("\n\0");

	//set the Global Descriptor Table
	gdt_install();

	//set the Interrupt Descriptor Table
	idt_install();

	//fill the IDT with interrupt functions
	isr_install();

	//reprogram the PIC
	PIC_install();

	//install the keyboard interrupt
	keyboard_install();

	//start the system clock
	time_install(1000); //1000hz

	printf("Int: %d \nChar: %c \nHex: %x \nOct: %o \nStr: %s \n\0",-85,"R",255,128,"Hello");

	set_text_green();
 
//exception test
#ifdef INSTA_FAIL
	int test = 0;
	__asm volatile ("div %b0" : "+a"(test));
#endif

	printf("DONE\n\0");

	while(true)
	{
		//printf("Millisecs since poweron: %d\n\0",get_system_uptime()); //TODO: make time accessable everywhere
		//unsigned char * temp = (unsigned char *)get_last_character();
		char temp = get_last_character();
		char * temp_2 = &temp;
		if (0x00 != temp)
		{
			//printf("%d ", temp);
			print_char(temp_2);
		}
	}
}
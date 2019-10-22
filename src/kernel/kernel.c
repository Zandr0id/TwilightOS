

#include "../include/stdlib.h"
#include "../include/stdio.h"
#include "../include/syslib.h"

//#define INSTA_FAIL

//extern "C" 
void kernel_main(void) 
{
	clear_screen();

	set_text_red();
    printf("   ____ _            ___  ____\n\0"); 
	printf(" / ___| |__   __ _ / _ \\/ ___|\n\0");
	printf("| |   | '_ \\ / _` | | | \\___ \\\n\0"); 
	printf("| |___| | | | (_| | |_| |___) |\n\0");
	printf(" \\____|_| |_|\\__,_|\\___/|____/\n\0");
	printf("\n\0");


	gdt_install();
	idt_install();
	isr_install();
	timer_install(20); //start the system clock

	printf("Int: %d \nChar: %c \nHex: %x \nOct: %o \nStr: %s \n\0",-85,"R",255,128,"Hello");

	set_text_green();

//exception test
#ifdef INSTA_FAIL
	int test = 0;
	__asm volatile ("div %b0" : "+a"(test));
#endif

	printf("DONE\n\0");
}
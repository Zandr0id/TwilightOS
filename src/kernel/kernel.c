

#include "../include/stdlib.h"
#include "../include/stdio.h"
#include "../include/syslib.h"

//extern "C" 
void kernel_main(void) 
{
	clear_screen();
	set_text_green();

	gdt_install();
	idt_install();
	isr_install();

	printf("Int: %d \nChar: %c \nHex: %x \nOct: %o \nStr: %s \n\0",-85,"R",255,128,"Hello");

	set_text_red();
	printf("HI There\n\0");

//exception test
	//int test = 0;
	//__asm volatile ("div %b0" : "+a"(test));

	printf("DONE\n\0");
}
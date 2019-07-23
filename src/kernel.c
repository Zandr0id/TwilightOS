

#include "libs/stdlib.h"

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

	//int test = 5/0;
	//printf("%i",test);

}
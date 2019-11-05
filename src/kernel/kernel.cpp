/*
	This is the kernel main! This is the entry point into the system
	It calls all the functions needed for the initial processor setup
*/

#include "../include/stdlib.h"
#include "../include/stdio.h"
#include "../include/syslib.h"
#include "../include/memory.h" //malloc

//#define INSTA_FAIL
#define MALLOC_TEST
#define PRINTF_TEST

//Forward declare this as Extern C so it can be called from Assembly code
extern "C"
{
	void kernel_main(void);
}

void kernel_main(void) 
{
	clear_screen();
	set_text_red();
	
	//print a really sweet message
	//Twilight is running!
	printf("  _____          _ _ _       _     _    \n"); 
	printf("|_   _|_      _(_) (_) __ _| |__ | |_  \n");
	printf("  | | \\ \\ /\\ / / | | |/ _` | '_ \\| __| \n");
	printf("  | |  \\ V  V /| | | | (_| | | | | |_  \n");
	printf("  |_|   \\_/\\_/ |_|_|_|\\__, |_| |_|\\__| \n");
	printf("                      |___/            \n"); 

	//set the Global Descriptor Table
	gdt_install();

	//set the Interrupt Descriptor Table
	idt_install();

	//fill the IDT with interrupt functions
	isr_install();

	//reprogram the PIC
	PIC_install();

	//install the heap
	heap_install();

	//install the keyboard interrupt
	keyboard_install();

	//start the system clock
	time_install(1000); //1000hz

	print_char("\n");

#ifdef PRINTF_TEST
	printf("Int: %d Char: %c Hex: %x \nOct: %o Str: %s \n\0",-85,"R",255,128,"Hello");
	//TODO: Fix %c to use ' ' instead of " "
#endif
	set_text_green();
	
	//dynamic memory testing
#ifdef MALLOC_TEST
	//turn on MALLOC_DEBUG for this
	printf("\nMalloc Test: \n");
	int * number = new int;
	*number = 10;
	char * number_2 = new char;
	*number_2 = 'T';
	delete number_2;
	int * number_3 = new int;	
	*number_3 = 418;
	delete number_3;
	int * number_4 = new int;
	*number_4 = 85;
#endif


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
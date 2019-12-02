/*
	This is the kernel main! This is the entry point into the system
	It calls all the functions needed for the initial processor setup
*/

#include <libc/stdlib.h>
#include <libc/stdio.h>
#include <libc/syslib.h>
#include <libc/memory.h> //malloc
#include <debugger_device.h>
#include <drivers/vga_device.h>
#include <paging.h>
#include <assert.h>
//#include <libc/vector.h>
//#include <libc/iterator.h>
//#include <libc/map.h>

//#define INSTA_FAIL
//#define MALLOC_TEST
//#define PRINTF_TEST
//#define SERIAL_TEST
//#define PAGING_TEST

//Forward declare this as Extern C so it can be called from Assembly code
extern "C"
{
	void kernel_main(void);
	void __cxa_pure_virtual(){};   // needed for pure virtual functions
}

void kernel_main(void)
{
	//install the heap
	heap_install();

	VGA_Device::Instance()->set_color(VGA_COLOR_RED,VGA_COLOR_BLACK);

	VGA_Device::Instance()->clear_screen();
	
	//print a really sweet message
	//Twilight is running!
	printf("  _____          _ _ _       _     _    \n"); 
	printf("|_   _|_      _(_) (_) __ _| |__ | |_  \n");
	printf("  | | \\ \\ /\\ / / | | |/ _` | '_ \\| __| \n");
	printf("  | |  \\ V  V /| | | | (_| | | | | |_  \n");
	printf("  |_|   \\_/\\_/ |_|_|_|\\__, |_| |_|\\__| \n");
	printf("                      |___/            \n"); 

	//begin paging
	paging_install();

	//reprogram the PIC
	PIC_install();

	//set the Global Descriptor Table
	gdt_install();

	//set the Interrupt Descriptor Table
	idt_install();

	//fill the IDT with interrupt functions
	isr_install();

	//install the keyboard interrupt
	keyboard_install();

	//start the system clock
	time_install(1000); //1000hz

	printf("\n");

/*
	Vector<int> test_vec;
	test_vec.push_back(5);
	test_vec.push_back(8);
	test_vec.push_back(-78);

	for(Iterator<Vector<int>> it = test_vec.begin(); it <= test_vec.end(); it++)
	{

	}

	printf("%d %d %d",test_vec.pop_back(),test_vec.pop_back(),test_vec.pop_back());


	Map<int, int> test_map;
	test_map.insert(1,4);
	test_map.insert(2,8);
*/

//printf test
#ifdef PRINTF_TEST
	printf("PRINTF_TEST\n");
	printf("Int: %d Char: %c Hex: %x \nOct: %o Str: %s \n",-85,"R",255,128,"Hello");
	//TODO: Fix %c to use ' ' instead of " "
#endif
	VGA_Device::Instance()->set_color(VGA_COLOR_GREEN,VGA_COLOR_BLACK);
	
//dynamic memory test
#ifdef MALLOC_TEST
	//turn on MALLOC_DEBUG for this
	printf("Malloc Test: \n");
	void * number1 = malloc(30);
	void * number2 = malloc(90);
	void * number3 = malloc(120);
	free(number1);
	//void * number3 = malloc(130);
	void * number4 = malloc(40);
	free(number2);
	free(number3);
	free(number4);
	free(number3);
#endif

#ifdef SERIAL_TEST
	//write_serial_string("This is testing the serial port!\n");
	printf("SERIAL_TEST\n");
	Debug_Logger::Instance()->print_string("Hello\n");
	Debug_Logger::Instance()->print_string("This is testing the serial port\n");
#endif

#ifdef PAGING_TEST
	printf("PAGING_TEST\n");
	auto * new_page = find_new_frame();
	printf("%x\n",new_page);
	auto * new_page2 = find_new_frame();
	printf("%x\n",new_page2);
	free_frame(new_page);
	auto * new_page3 = find_new_frame();
	printf("%x\n",new_page3);
#endif

//exception test
#ifdef INSTA_FAIL
	printf("FAIL_TEST\n");
	int test = 0;
	__asm volatile ("div %b0" : "+a"(test));
#endif
	printf("DONE\n");

	while(true)
	{
		//printf("Millisecs since poweron: %d\n\0",get_system_uptime()); //TODO: make time accessable everywhere
		//unsigned char * temp = (unsigned char *)get_last_character();
		//char temp = get_last_character();
		//char * temp_2 = &temp;
		//if (0x00 != temp)
		//{
		//	VGA_Device::Instance()->put_char(temp_2);
		//	Debug_Logger::Instance()->print_char(temp_2);
		//}
	}
}
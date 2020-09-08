/*
	This is the kernel main! This is the entry point into the system
	It calls all the functions needed for the initial processor setup
*/

#include <libc/stdlib.h>
#include <libc/stdio.h>
#include <libc/syslib.h>
#include <libc/memory.h> //malloc
#include <debugger_device.h>
#include <paging.h>
#include <assert.h>
#include <libc/vector.hpp>
#include <libc/queue.hpp>

//#define ALL_TESTS

//#define INSTA_FAIL
//#define MALLOC_TEST
//#define PRINTF_TEST
//#define SERIAL_TEST
//#define PAGING_TEST
#define VECTOR_TEST
//#define TIME_TEST
 
#ifdef ALL_TESTS
#define TIME_TEST
#define INSTA_FAIL
#define MALLOC_TEST
#define PRINTF_TEST
#define SERIAL_TEST
#define PAGING_TEST
#define VECTOR_TEST
#endif

//Forward declare this as Extern C so it can be called from Assembly code
extern "C"
{
	void kernel_main(void);
	void __cxa_pure_virtual(){};   // needed for pure virtual functions
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

	//install the heap
	heap_install();

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

	print_char("\n");

//printf test
#ifdef PRINTF_TEST
	printf("PRINTF_TEST\n");
	printf("Int: %d Char: %c Hex: %x \nOct: %o Str: %s \n",-85,"R",255,128,"Hello");
	//TODO: Fix %c to use ' ' instead of " "
	printf("END PRINTF_TEST\n");
#endif
	set_text_green();
	
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
	//free(number3);
	printf("END MALLOC_TEST\n");
#endif

#ifdef SERIAL_TEST
	//write_serial_string("This is testing the serial port!\n");
	printf("SERIAL_TEST\n");
	Debug_Logger::Instance()->print_string("Hello\n");
	Debug_Logger::Instance()->print_string("This is testing the serial port\n");
	printf("look in the terminal...\n");
	printf("END SERIAL_TEST\n");
#endif

#ifdef VECTOR_TEST
	printf("VECTOR_TEST\n");
	Vector<int> vec;
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(10);
	int test1 = vec.pop_back();
	int test2 = vec.pop_back();
	int test3 = vec.pop_back();
	printf("%d %d %d\n",test1,test2,test3);
	printf("END VECTOR_TEST\n");

	printf("QUEUE_TEST\n");
	Queue<int> queue;
	printf("size: %d\n",queue.size());
	queue.push(12);
	queue.push(-9);
	queue.push(5);
	printf("%d ",queue.pop());
	printf("%d ",queue.pop());
	printf("%d ",queue.pop());
	printf("size: %d\n",queue.size());
	printf("END QUEUE_TEST\n");
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
	printf("END PAGING_TEST\n");
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
		#ifdef TIME_TEST
		unsigned int sys_time = get_system_uptime();
		if (0 == (sys_time % 1000))
		{
			printf("Millisecs since poweron: %d\n\0",(sys_time/1000)); //TODO: make time accessable everywhere
		}
		#endif

		//unsigned char * temp = (unsigned char *)get_last_character();
		char c = getchar();
		auto add = &c;
		if (0x00 != c)
		{
			//printf("%d ", temp);
			print_char(add);
		}
	}
}
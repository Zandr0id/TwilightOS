#include "../include/syslib.h"
#include "../include/stdio.h"
#include "../include/isr_helper.h"

int ticks = 0;

void timer_callback()//struct regs *r)
{
    ticks++;
    printf("Tick %d\n\0",ticks);
      
}

void timer_install(int freq)
{
    register_interrupt_handler(32, &timer_callback);

    printf("Install Timer at %dHz\n\0",freq);
    int divisor = 1193180 / freq;
    char low = (char)(divisor & 0xFF);
    char high = (char)((divisor >> 8) & 0xFF);

    outb(0x43,0x36);
    outb(0x40,low);
    outb(0x40,high);
}

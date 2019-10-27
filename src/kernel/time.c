#include "../include/stdio.h"
#include "../include/isr_helper.h"
#include "../include/time.h"

static time_data time; // the master system clock, for now

void timer_callback()//struct regs *r)
{
    increment_time(&time);
}

unsigned int get_system_uptime()
{
    return time.millisecs_since_poweron;
}

void time_install(int freq)
{
    register_interrupt_handler(32, &timer_callback);

    printf("Install Timer at %dHz\n\0",freq);
    int divisor = 1193180 / freq;

    //the top and bottom bytes of the divisor must be sent separately
    char low = (char)(divisor & 0xFF);
    char high = (char)((divisor >> 8) & 0xFF);

    //set PIT channel 0 to use the new divisor
    outb(PIT_CMD,0x36);
    outb(PIT_CHANNEL_0,low);
    outb(PIT_CHANNEL_0,high);
}

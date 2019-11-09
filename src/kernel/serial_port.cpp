#include "../include/stdio.h"
#include "../include/serial_port.h"
#include "../include/isr_helper.h"


void serial_port_callback()
{
    //TODO: implement me!!!
}

void serial_install()
{
    outb(COM1+1,0x00);//disable interrupts
    outb(COM1+3,0x80);//
    outb(COM1+0,0x03);
    outb(COM1+1,0x00);
    outb(COM1+3,0x03);
    outb(COM1+2,0xC7);
    outb(COM1+4,0x0B);

    register_interrupt_handler(36, (isr_t)serial_port_callback);
}

//Check if nothing is being transmitted at the moment
int check_TX_empty()
{
    int num = inb(COM1+5) & 0x20;
    return num;
}

void write_char_serial(char c)
{
    while (check_TX_empty() == 0); //sit here until TX buffer is empty 
  
    outb(COM1, c);
}

void write_serial_string(const char *c)
{
    while(*c != '\0')
    {
        //print_char(c);
        write_char_serial(*c);
        c++;
    }
}
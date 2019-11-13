#include <libc/stdio.h>
#include <drivers/serial_port.h>
#include <arch/x86/isr_helper.h>



Serial_port::Serial_port(short port_number)
{
    com_port_num_ = port_number; //save the port number, because reasons

    outb(port_number+1,0x00);//disable interrupts
    outb(port_number+3,0x80);//
    outb(port_number+0,0x03);
    outb(port_number+1,0x00);
    outb(port_number+3,0x03);
    outb(port_number+2,0xC7);
    outb(port_number+4,0x0B);
}

int Serial_port::get_port_num()
{
    return com_port_num_;
}

void Serial_port::print(const char * string_to_print)
{
    while(*string_to_print != '\0') //check if it's the end of the string
    {
        while((inb(com_port_num_+5) & 0x20) == 0); //make sure the TX buffer is empty
    
        outb(com_port_num_, *string_to_print); //print the char
        string_to_print++; //next char
    }
}

char * Serial_port::read()
{
    return rx_buff;
}

void serial_port_callback()
{
    //TODO: implement me!!!
}

void serial_tx_install()
{    
    //register_interrupt_handler(36, (isr_t)serial_port_callback);
}


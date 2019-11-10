
#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_

#include "../include/memory.h"
#include "../include/stdio.h"

enum Serial_port_keywords
{
    COM1 = 0x3F8,
    COM2 = 0x2F8,
    COM3 = 0x3E8,
    COM4 = 0x2E8
};

class Serial_port
{
public:
    Serial_port(short port_number); //private constructor
    void print(const char * string_to_print);
    char * read();
    int get_port_num(); //return the port number being used
private:
    int com_port_num_;
    char rx_buff[128]; //store incoming data here
};

#endif
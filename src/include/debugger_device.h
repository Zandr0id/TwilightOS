#ifndef DEBUGGER_DEVICE_H_
#define DEBUGGER_DEVICE_H_

#include <drivers/serial_port.h>
#include <basics.h>

class Debug_Logger
{
public:
    static Debug_Logger * Instance();
    void print_string(const char * string_to_print);
    void print_char(const char * c);
private:
    Debug_Logger();
    Serial_port * output; //where should output go?
    static Debug_Logger * instance_;
};

#endif
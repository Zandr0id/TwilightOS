#ifndef DEBUGGER_DEVICE_H_
#define DEBUGGER_DEVICE_H_

#include "../include/serial_port.h"
#include "../include/basics.h"

class Debug_Logger
{
public:
    static Debug_Logger * Instance();
    void print(const char *);
private:
    Debug_Logger();
    Serial_port * output; //where should output go?
    static Debug_Logger * instance_;
};

#endif
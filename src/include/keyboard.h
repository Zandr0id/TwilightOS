/*
keyboard.h

*/
#include "../include/basics.h"

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

enum Keyboard_Ports
{
    Keyboard_Encoder = 0x60,
    Keyboard_Controller = 0x64
};

typedef struct keyboard_scancode_buffer
{
    bool modified_table;
    unsigned char scancode;
}keyboard_scancode_buffer;

#endif
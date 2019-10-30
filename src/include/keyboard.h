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
    bool shift_pressed;
    unsigned char scancode;
}keyboard_scancode_buffer;

enum Keyboard_Keys
{
    Keyboard_A = 0x1E,
    Keyboard_B = 0x30,
    Keyboard_C = 0x2E,
    Keyboard_D = 0x20,
    Keyboard_E = 0x12,
    Keyboard_F = 0x21,
    Keyboard_G = 0x22,
    Keyboard_H = 0x23,
    Keyboard_I = 0x17,
    Keyboard_J = 0x24,
    Keyboard_K = 0x25,
    Keyboard_L = 0x26,
    Keyboard_M = 0x32,
    Keyboard_N = 0x31,
    Keyboard_O = 0x18,
    Keyboard_P = 0x19,
    Keyboard_Q = 0x10,
    Keyboard_R = 0x13,
    Keyboard_S = 0x1F,
    Keyboard_T = 0x14,
    Keyboard_U = 0x16,
    Keyboard_V = 0x2F,
    Keyboard_W = 0x11,
    Keyboard_X = 0x2D,
    Keyboard_Y = 0x15,
    Keyboard_Z = 0x2C,
    Keyboard_SHIFT_L_PRESS = 0x2A,
    Keyboard_SHIFT_R_PRESS = 0x36,
    Keyboard_SHIFT_L_RELEASE = 0xAA,
    Keyboard_SHIFT_R_RELEASE = 0xB6,
    Keyboard_ENTER = 0x1C,
    Keyboard_SPACE = 0x39,
    Keyboard_TOGGLE = 0xE0
};

#endif
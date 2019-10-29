#include "../include/keyboard.h"
#include "../include/stdio.h"
#include "../include/isr_helper.h"

static keyboard_scancode_buffer keyboard_buffer;

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
    Keyboard_SPACE = 0x39,
    Keyboard_TOGGLE = 0xE0
};

void keyboard_callback()
{
    unsigned char scancode = inb(Keyboard_Encoder);
    //printf("Scancode: %x\n", scancode);
    if (Keyboard_TOGGLE == scancode)
    {
        keyboard_buffer.modified_table = true;
    }
    else
    {
        keyboard_buffer.scancode = scancode;
    }
}

int get_last_character()
{
    if (
        Keyboard_A == keyboard_buffer.scancode) 
    {
        keyboard_buffer.scancode = 0;
        return 'a';
    }
    else if (Keyboard_B == keyboard_buffer.scancode )
    {
        keyboard_buffer.scancode = 0;
        return 'b';
    }
    else if (Keyboard_C == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'c';
    }
        else if (Keyboard_D == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'd';
    }
        else if (Keyboard_E == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'e';
    }
        else if (Keyboard_F == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'f';
    }
        else if (Keyboard_G == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'g';
    }
        else if (Keyboard_H == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'h';
    }
        else if (Keyboard_I == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'i';
    }
        else if (Keyboard_J == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'j';
    }
        else if (Keyboard_K == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'k';
    }
        else if (Keyboard_L == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'l';
    }
        else if (Keyboard_M == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'm';
    }
        else if (Keyboard_N == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'n';
    }
        else if (Keyboard_O == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'o';
    }
        else if (Keyboard_P == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'p';
    }
        else if (Keyboard_Q == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'q';
    }
        else if (Keyboard_R == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'r';
    }
        else if (Keyboard_S == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 's';
    }
        else if (Keyboard_T == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 't';
    }
        else if (Keyboard_U == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'u';
    }
        else if (Keyboard_V == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'v';
    }
        else if (Keyboard_W == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'w';
    }
        else if (Keyboard_X == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'x';
    }
        else if (Keyboard_Y == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'y';
    }
        else if (Keyboard_Z == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return 'z';
    }
        else if (Keyboard_SPACE == keyboard_buffer.scancode)
    {
        keyboard_buffer.scancode = 0;
        return ' ';
    }
    else
    {
        keyboard_buffer.scancode = 0;
        return 0x00;
    }
    
}

void keyboard_install()
{
    printf("Install Keyboard\n\0 ");
    register_interrupt_handler(33, &keyboard_callback);
}


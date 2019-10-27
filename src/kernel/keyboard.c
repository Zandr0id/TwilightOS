#include "../include/keyboard.h"
#include "../include/stdio.h"
#include "../include/isr_helper.h"


void keyboard_callback()
{
    //printf("key pressed\n");
    unsigned char scancode = inb(Keyboard_Encoder);
    printf("Scancode: %d\n", scancode);
}


void keyboard_install()
{
    printf("Install Keyboard\n\0 ");
    register_interrupt_handler(33, &keyboard_callback);
}
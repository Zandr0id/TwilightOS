#include "../include/keyboard.h"
#include "../include/stdio.h"
#include "../include/isr_helper.h"


void keyboard_callback()
{
    printf("key pressed\n");
}


void keyboard_install()
{
    printf("Install Keyboard\n\0 ");
    register_interrupt_handler(33, &keyboard_callback);
}
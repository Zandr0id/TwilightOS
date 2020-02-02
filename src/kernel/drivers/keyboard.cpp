
#include <drivers/keyboard.h>
#include <libc/map.h>
#include <libc/stdio.h>
#include <arch/x86/isr_helper.h>
#include <drivers/vga_device.h>
#include <debugger_device.h>

//#define KEYBOARD_DEBUG

static keyboard_state_buffer keyboard_buffer;
//static Map<int,char> lower_keymap;
//static Map<int,char> upper_keymap;

//every time a key gets hit, grab the scancode and update the keyboard state buffer
void keyboard_callback()
{
    unsigned char scancode = inb(Keyboard_Encoder);
#ifdef KEYBOARD_DEBUG
    printf("Scancode: %x\n", scancode);
#endif

    if (Keyboard_TOGGLE == scancode)
    {
        keyboard_buffer.modified_table = true;
    }
    else if ((Keyboard_SHIFT_L_PRESS == scancode) || (Keyboard_SHIFT_R_PRESS == scancode))
    {
        keyboard_buffer.shift_pressed = true;
    }
    else if ((Keyboard_SHIFT_L_RELEASE == scancode) || (Keyboard_SHIFT_R_RELEASE == scancode))
    {
        keyboard_buffer.shift_pressed = false;
    }
    else
    {
        keyboard_buffer.scancode = scancode;
    }

		char temp = get_last_character();
		char * temp_2 = &temp;
		if (0x00 != temp)
		{
			VGA_Device::Instance()->put_char(temp_2);
			//Debug_Logger::Instance()->print_char(temp_2);
		}
}

//Look at the keyboard state buffer and decide the character to send
char get_last_character()
{
    char return_char;
    //lower_keymap.search(keyboard_buffer.scancode, return_char);
    //return return_char;
    
    switch (keyboard_buffer.scancode)
    {
        case Keyboard_A: 
        {   
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'A';
            }
            else
            {
                return_char ='a';
            }
            break;
        }
        case Keyboard_B:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'B';
            }
            else
            {
                return_char = 'b';
            }
            break;
        }
        case Keyboard_C:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'C';
            }
            else
            {
                return_char = 'c';
            }
            break;
        }
        case Keyboard_D:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'D';
            }
            else
            {
                return_char = 'd';
            }
            break;
        }
        case Keyboard_E: 
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'E';
            }
            else
            {
                return_char = 'e';
            }
            break;
        }
        case Keyboard_F: 
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'F';
            }
            else
            {
                return_char = 'f';
            }
            break;
        }
        case Keyboard_G:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'G';
            }
            else
            {
                return_char = 'g';
            }
            break;
        }
        case Keyboard_H:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'H';
            }
            else
            {
                return_char = 'h';
            }
            break;
        }
        case Keyboard_I:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'I';
            }
            else
            {
                return_char = 'i';
            }
            break;
        }
        case Keyboard_J:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'J';
            }
            else
            {
                return_char = 'j';
            }
            break;
        }
        case Keyboard_K:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'K';
            }
            else
            {
                return_char = 'k';
            }
            break;
        }
        case Keyboard_L:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'L';
            }
            else
            {
                return_char = 'l';
            }
            break;
        }
        case Keyboard_M: 
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'M';
            }
            else
            {
                return_char = 'm';
            }
            break;
        }
        case Keyboard_N:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'N';
            }
            else
            {
                return_char = 'n';
            }
            break;
        }
        case Keyboard_O:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'O';
            }
            else
            {
                return_char = 'o';
            }
            break;
        }
        case Keyboard_P:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'P';
            }
            else
            {
                return_char = 'p';
            }
            break;
        }
        case Keyboard_Q:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'Q';
            }
            else
            {
                return_char = 'q';
            }
            break;
        }
        case Keyboard_R:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'R';
            }
            else
            {
                return_char = 'r';
            }
            break;
        }
        case Keyboard_S:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'S';
            }
            else
            {
                return_char = 's';
            }
            break;
        }
        case Keyboard_T:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'T';
            }
            else
            {
                return_char = 't';
            }
            break;
        }
        case Keyboard_U:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'U';
            }
            else
            {
                return_char = 'u';
            }
            break;
        }
        case Keyboard_V:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'V';
            }
            else
            {
                return_char = 'v';
            }
            break;
        }
        case Keyboard_W:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'W';
            }
            else
            {
                return_char = 'w';
            }
            break;
        }
        case Keyboard_X:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'X';
            }
            else
            {
                return_char = 'x';
            }
            break;
        }
        case Keyboard_Y:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'Y';
            }
            else
            {
                return_char = 'y';
            }
            break;
        }
        case Keyboard_Z:
        {
            if (true == keyboard_buffer.shift_pressed)
            {
                return_char = 'Z';
            }
            else
            {
                return_char = 'z';
            }
            break;
        }
        case Keyboard_SPACE:
        {
            return_char = ' ';
            break;
        }
        case Keyboard_ENTER:
        {
            return_char = '\n';
            break;
        }
        default:
        {
            return_char = 0x00;
            break;
        }
    }
    keyboard_buffer.scancode = 0;
    return return_char;
    
}

/*
void fill_keyboard_map()
{
    lower_keymap.insert(Keyboard_A,'a');
    lower_keymap.insert(Keyboard_B,'b');
    lower_keymap.insert(Keyboard_C,'c');
    lower_keymap.insert(Keyboard_D,'d');
    lower_keymap.insert(Keyboard_E,'e');
    lower_keymap.insert(Keyboard_F,'f');
    lower_keymap.insert(Keyboard_G,'g');
    lower_keymap.insert(Keyboard_H,'h');
    lower_keymap.insert(Keyboard_I,'i');
    lower_keymap.insert(Keyboard_J,'j');
    lower_keymap.insert(Keyboard_K,'k');
    lower_keymap.insert(Keyboard_L,'l');
    lower_keymap.insert(Keyboard_M,'m');
    lower_keymap.insert(Keyboard_N,'n');
    lower_keymap.insert(Keyboard_O,'o');
    lower_keymap.insert(Keyboard_P,'p');
    lower_keymap.insert(Keyboard_Q,'q');
    lower_keymap.insert(Keyboard_R,'r');
    lower_keymap.insert(Keyboard_S,'s');
    lower_keymap.insert(Keyboard_T,'t');
    lower_keymap.insert(Keyboard_U,'u');
    lower_keymap.insert(Keyboard_V,'v');
    lower_keymap.insert(Keyboard_W,'w');
    lower_keymap.insert(Keyboard_X,'x');
    lower_keymap.insert(Keyboard_Y,'y');
    lower_keymap.insert(Keyboard_Z,'z');
    lower_keymap.insert(Keyboard_SPACE,' ');
    lower_keymap.insert(Keyboard_ENTER,'\n'); 
}
*/

void keyboard_install()
{
    printf("Install Keyboard\n\0 ");
    register_interrupt_handler(33, (isr_t)keyboard_callback);
    //fill_keyboard_map();
}

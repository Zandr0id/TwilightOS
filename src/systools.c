
//this systools file is where uncatagorized but useful functions can be defined.
#include "stdlib.h"

//takes to chars as locations and copies one to another
unsigned char* memcpy(unsigned char* dest, unsigned char* src, int count)
{
    for (int i=0; i<count; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

//takes a char location and a char value to place count number of slots
unsigned char* memset(unsigned char* dest, unsigned char val, int count)
{
    for (int i=0; i<count; i++)
    {
         *(dest+i) = val;
    }
    return dest;
}

//same as above but with shorts
/*
unsigned short* memsetw(unsigned short* dest, unsigned short val, int count)
{
    for (int i=0; i<count; i++)
    {
        dest[i] = val;
    }
    return dest;
}
*/

//returns the length of the string
//a \0 denotes the end of a string
//make sure it's added at the end of string literals to print
int strlen(const char* data)
{
    int len = 0;
    while(data[len] != '\0')
    {
        len++;
    }
    return len;
}

//prints out a number as a hex string
/*
This was a tricky one to make
This algorithm ends up filling the char array 
in reverse with the hex digits.
*/
void hex_string(unsigned int num)
{
    print("0x");
    int temp = num;
    char result = 0;
    int spot = 0;
    char * out = 0;

    while (temp != 0)
    {
        result = temp % 16;
        if (result < 10)
        {
            result = result + 48;
        }
        else
        {
            result = result + 55;
        }
        out[spot] = result;
        spot++;
        temp = temp / 16;
    }
    spot--;
    /*
    The print function watches for a \0 to stop,
    so I have to send it each individual digit with a \0 after it
    it's kind of hacky.....
    */
    char flipped[2];    
    for (int j=0; j<=spot; j++)
    {
        flipped[0] = out[spot-j];
        flipped[1]='\0';
        print(flipped);
    }

}


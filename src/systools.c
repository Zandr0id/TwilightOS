
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
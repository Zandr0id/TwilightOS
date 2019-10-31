
//this is where the functions unique to stdlib will be implemented

#include "../include/stdlib.h"

//takes to chars as locations and copies one to another
void memcpy(void * dest, const void * src, int count)
{
    const char * src_ptr = (const char *)src;
    char * dest_ptr = (char*)dest;
    for(;count > 0;count--)
    {
        *dest_ptr++ = *src_ptr++;
    }
}

//takes a char location and a char value to place count number of slots
void memset(void * dest, char val, int count)
{
    char *temp = (char *)dest;

    for (; count>0; count--)
    {
         *temp = val;
         temp+=sizeof(char);
    }
}

//same as above but with shorts
void memsetw(void* dest, unsigned short val, int count)
{
    unsigned short *temp = (unsigned short *)dest;
    for (; count>0; count--)
    {
         *temp = val;
         temp+=sizeof(short);
    }
}

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

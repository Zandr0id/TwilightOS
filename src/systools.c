
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
        dest[i] = val;
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
int strlen(const char* data)
{
    int len = 0;
    while(data[len])
    {
        len++;
    }
    return len;
}

//returns a number as a hex string
void hex_string(unsigned int num, char* ret)
{

    ret[0]='0';
    ret[1]='x';

	long int decimalNumber,remainder,quotient;
	int i=1,j,temp;

	quotient = (long) num;
	while(quotient!=0) {
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
		           temp =temp + 48; else
		         temp = temp + 55;
		ret[i++]= temp;
		quotient = quotient / 16;
	}
}


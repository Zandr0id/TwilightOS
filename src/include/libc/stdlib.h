//this is standard lib!
// This H file will be included into the kernel, and all other files will be liked into this one.

#ifndef STDLIB_H
#define STDLIB_H

#include <basics.h>

//memory related functions
extern void memcpy(void * dest, const void * src, int count);
extern void memset(void * dest, char val, int count);
extern void memsetw(void* dest, unsigned short val, int count);
extern int strlen(const char* data);


#endif //STDLIB_H
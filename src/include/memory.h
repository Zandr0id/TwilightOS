/*
memory.h
This is the header for dynamic memory allocation functions
Written by Zane Youmans
11/02/2019
*/
#include "../include/basics.h"

#ifndef MEMORY_H_
#define MEMORY_H_

enum Heap_keywords
{
    //HEAP_BLOCK_SIZE = 8, //minimum one byte per block
    //HEAP_BLOCK_HEADER_SIZE = 4, //block header is 4 bytes, to hold size of allocation
    HEAP_SIZE = 1024 //how many bytes the heap is
};

/*
#pragma(pack(2))
typedef struct Heap
{
    bool bit_mask[HEAP_SIZE]; //the bitmask to know what is in use
    unsigned char pool[HEAP_SIZE]; //the actual heap
    void * location; // the physical memory location of this Heap
}Heap;
*/

//void heap_install(); //initialize the heap
void * malloc(size_t size); //memory allocate
void free(void * loc); //memory free
//void * operator new (size_t size); //implement the N

#endif //MEMORY_H_
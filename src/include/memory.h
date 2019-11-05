/*
memory.h
This is the header for dynamic memory allocation functions
Written by Zane Youmans
11/02/2019
*/
#include "../include/basics.h"

#ifndef MEMORY_H_
#define MEMORY_H_

enum Heap_constants
{
    //HEAP_BLOCK_SIZE = 8, //minimum one byte per block
    HEAP_MINIMUM_BLOCK_SIZE = 64, //Minimum size of block payload to allow splitting
    HEAP_ETERNAL_SIZE = 1024, //how many bytes the eternal heap is
    HEAP_DYNAMIC_SIZE = 16384 //how many bytes the dynamic heap is
};

//this will go at the front of every malloc segment
#pragma pack(2)
typedef struct Heap_element_header
{
    Heap_element_header * next; //pointer to the next header
    unsigned int payload_size; //number of bytes in this block
    bool in_use; //is this block in use?
}Heap_element_header;

void heap_install(); //initialize the heap
void * malloc(size_t size); //memory allocate
//void * malloc_eternal(size_t size); //eternal memeory allocate
void free(void * loc); //memory free

#endif //MEMORY_H_
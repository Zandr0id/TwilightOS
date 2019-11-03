#include "../include/memory.h"

//static Heap kernel_heap;
static char * kernel_heap = (char * )0x10FFF0; //TODO: put in specific spot

void * malloc(size_t size)
{
    void * loc = kernel_heap;
    kernel_heap += size;
    return loc;
}

void free(void * loc)
{
    loc = loc;
    //TODO: Implement me!!!
}

void * operator new (size_t size)
{
    return malloc(size);
}

void operator delete (void* ptr)
{
    free(ptr);
}

void operator delete (void* ptr, size_t size)
{
    size = size;
    free(ptr);
}


/*
void install_heap()
{
    //kernel_heap.location = &kernel_heap;
}
*/

/*
void * malloc(size_t size)
{
    int total_allocation_request_size = (size + HEAP_BLOCK_HEADER_SIZE);

    int located_index = -1; //index of the bitmask that is large enough

    for(int index = 0; index < (HEAP_SIZE-total_allocation_request_size); index++)
    {
        if(false == kernel_heap.bit_mask[index])
        {
            for(int contiguous = index; contiguous < (index+total_allocation_request_size); contiguous++)
            {
                if(true == kernel_heap.bit_mask[contiguous])
                {
                    index = contiguous;
                    break;
                }
                else
                {
                    continue;
                }
            }
            located_index = index; //save the index of the first contiguous bit
            break;
        }
    }

    if(located_index < 0)
    {
        return nullptr;
    }
    else
    {
        int * header_address = (int *)kernel_heap.pool[located_index]; 
        *header_address = size;
        return ((char*)(header_address) + HEAP_BLOCK_HEADER_SIZE);
    }
}

void free(void * location)
{
    long long offset = (((char *)(location) - (char *)(kernel_heap.location)));
    int size =
    int index_to_free = (offset/HEAP_BLOCK_SIZE);

    for(int index = index_to_free; index_to_free <)
}

*/
#include "../include/memory.h"
#include "../include/stdio.h"

#define MALLOC_DEBUG

//static Heap kernel_heap;
//static char * eternal_heap = (char * )(0x100000+DYNAMIC_HEAP_SIZE+512); //TODO: put in specific spot
static Heap_element_header * kernal_heap_start = (Heap_element_header * )0x200000;
/*
void * malloc_eternal(size_t size)
{
    void * loc = eternal_heap;
    eternal_heap += size;
    return loc;
}
*/

int amount_of_free_heap()
{
    int free_heap = 0;
    Heap_element_header * current_header = kernal_heap_start;
    while(true)
    {
        if(false == current_header->in_use)
        {
            free_heap += current_header->payload_size;
        }
 
        if(nullptr != current_header->next)
        {
            current_header = current_header->next;
        }
        else
        {
            break;
        }
        
    }
    return free_heap;
}


void * malloc(size_t size)
{
    unsigned int total_allocation_size = size + sizeof(Heap_element_header);

#ifdef MALLOC_DEBUG
    printf("Before Malloc %d : %d\n",total_allocation_size, amount_of_free_heap());
#endif
    //printf("Allocation size: %d\n", total_allocation_size);

    Heap_element_header * current_header = kernal_heap_start;

    //jump from one header to the next until we find one that is not in use
    while(true)
    {
        if((false==current_header->in_use) && (current_header->payload_size >= total_allocation_size))
        {
            break;
        }
        if(nullptr != current_header->next)
        {   
            current_header = current_header->next; // move to the next header
            //printf("jump1\n");
        }
        else
        {
            return nullptr;
        }
    }

    //we've found a free spot!!!
    Heap_element_header * new_header = (current_header + total_allocation_size);
    new_header->in_use = false;
    new_header->next = nullptr;
    new_header->payload_size = (current_header->payload_size - total_allocation_size);

    //fill in our current header with its new info
    current_header->next = new_header;
    current_header->in_use = true;
    current_header->payload_size = size;

#ifdef MALLOC_DEBUG
    printf("After Malloc %d : %d\n",total_allocation_size, amount_of_free_heap());
#endif
    return (current_header + sizeof(Heap_element_header));
}

void free(void * loc)
{
    Heap_element_header * to_free = (Heap_element_header *)(loc) - sizeof(Heap_element_header);
#ifdef MALLOC_DEBUG
    int size = to_free->payload_size;
    printf("Before Free %d : %d\n",size, amount_of_free_heap());
#endif
     to_free->in_use = false;
#ifdef MALLOC_DEBUG
    printf("After Free %d : %d\n",size, amount_of_free_heap());
#endif
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

void heap_install()
{
   // Heap_element_header * heap_top = kernal_heap_start;
    kernal_heap_start->in_use = false;
    kernal_heap_start->payload_size = (DYNAMIC_HEAP_SIZE - sizeof(Heap_element_header));
    kernal_heap_start->next = nullptr;
}
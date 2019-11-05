#include "../include/memory.h"
#include "../include/stdio.h"

#define MALLOC_DEBUG

//static Heap kernel_heap;
//static char * eternal_heap = (char * )(0x100000+DYNAMIC_HEAP_SIZE+512); //TODO: put in specific spot
static Heap_element_header * kernel_heap_start = (Heap_element_header * )0x200000;
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
    Heap_element_header * current_header = kernel_heap_start;
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

void merge_free_blocks()
{
    Heap_element_header * current_header = kernel_heap_start;

    //don't start on nullptr, you're at the end
    while(nullptr != current_header->next)
    {
        Heap_element_header * first_free_block;
        if(false == current_header->in_use)
        {
            first_free_block = current_header;
            while((false == current_header->in_use) && (nullptr != current_header->next))
            {
                current_header = current_header->next;
            } 
            first_free_block->next = current_header;
            printf("merge %d + %d\n",first_free_block->payload_size, current_header->payload_size);
        }
        current_header = current_header->next;
        //printf("loop\n");
    }
}

void * malloc(size_t size)
{

    if (size < HEAP_MINIMUM_BLOCK_SIZE)
    {
        size = HEAP_MINIMUM_BLOCK_SIZE;
    }
    unsigned int total_allocation_size = size + sizeof(Heap_element_header);

#ifdef MALLOC_DEBUG
    printf("Before Malloc %d : %d\n",total_allocation_size, amount_of_free_heap());
#endif
    //printf("Allocation size: %d\n", total_allocation_size);

    Heap_element_header * current_header = kernel_heap_start;

    //jump from one header to the next until we find one that is not in use
    while(true)
    {
        //check if the block is unused, and large enough for our need
        if((false==current_header->in_use) && (current_header->payload_size >= size))
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

   //We already know the block is big enough to use, but if it's big enough to split then we should...
   //By "big enough", I mean we can get at least a minimum sized block out of it.
    if(current_header->payload_size >= ((size+HEAP_MINIMUM_BLOCK_SIZE)+sizeof(Heap_element_header)))
    {
        printf("Split a block\n");
        Heap_element_header * new_header = (current_header + total_allocation_size);
        new_header->in_use = false;
        new_header->next = current_header->next;
        new_header->payload_size = (current_header->payload_size - total_allocation_size);

        current_header->next=new_header;
        current_header->payload_size = size;    
    }

    //make note that this block is now being used
    current_header->in_use = true;
    
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
    merge_free_blocks();

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
    kernel_heap_start->in_use = false;
    kernel_heap_start->payload_size = (HEAP_DYNAMIC_SIZE - sizeof(Heap_element_header));
    kernel_heap_start->next = nullptr;
}
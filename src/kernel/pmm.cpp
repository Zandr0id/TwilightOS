#include <pmm.h>
#include <libc/stdio.h>
#include <assert.h>

//#define DEBUG

static frame * frame_field = (frame *)0x40000000; //the start of the frame field is at the 1 gig mark, and is 1 gig in size

//TODO: make the magic number a const somehow....
static unsigned int frame_field_bitmap[8192]; //this is how many ints can fit in the frame_field

void paging_install()
{
    printf("Install Paging\n");
    for (int i=0;i<8192;i++)
    {
        frame_field_bitmap[i] = 0; //zero out the whole bitmap
    }
}

void * find_new_frame()
{
    int major_index = -1;
    int minor_index = -1;
    for (int i=0;i<8192;i++) //TODO: magic number no bueno
    {
        if(frame_field_bitmap[i] != 0xFFFFFFFF) //this section is not full and must have free spot
        {
            unsigned int bitmap_cpy = frame_field_bitmap[i]; //make a copy so the real one doesn't get screwed up my mistake
#ifdef DEBUG
            printf("Start: %x\n", bitmap_cpy);
#endif
            int tmp_index = 0;
            while(bitmap_cpy & 0x80000000) //see if the MSB is not a zero
            {
                tmp_index++;
                bitmap_cpy = bitmap_cpy << 1;
            }
            minor_index = tmp_index; //the number if ints into the bitmap
            major_index = i; //how many bits into the current

            frame_field_bitmap[major_index] = (frame_field_bitmap[major_index] | (1<<(31-minor_index))); //mark that frame taken in the bitmask
#ifdef DEBUG
            printf("End: %x\n", frame_field_bitmap[major_index]);
            printf("Mjr: %d Mnr: %d\n",major_index,minor_index);
#endif
            int bitmask_index = ((sizeof(unsigned int)*major_index) + minor_index); //get the number of bits into the bitmap of a hole
            return (frame_field + bitmask_index); // return the address of the free frame! 
        }
    }  
    ASSERT_NOT_REACHED(); //if we got here, something went wrong!
}

void free_frame(void * frame_to_free)
{
 
    CHECK((unsigned int)frame_to_free >= (unsigned int)frame_field);

    unsigned int * bits = &frame_field_bitmap[((frame *)frame_to_free - frame_field) / (sizeof(unsigned int) * 8)]; //find the index into the bitmap
    unsigned int mask = 1U << (31 - ((frame *)frame_to_free - frame_field) % (sizeof(unsigned int) * 8)); //find the specific bit to flip
    *bits &= ~mask; //and flip it 
}

 
 

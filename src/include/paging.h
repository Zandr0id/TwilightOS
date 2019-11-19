#ifndef PAGING_H_
#define PAGING_H_

#include <basics.h>


const int FRAME_SIZE = 4096; //frames will be 4KiB each
const int NUMBER_OF_FRAMES = 262144; //1 Gig worth of frames

struct frame
{
    unsigned char frames[FRAME_SIZE];
};

void * find_new_frame();
void free_frame(void * frame_to_free);

#endif
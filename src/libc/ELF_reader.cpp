#include "ELF_Types.h"
#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{

    File_Header Elf_header;
    std::ifstream elf_file;
    elf_file.open(argv[1], std::ios::in | std::ios::binary);

    char magic[64];

    elf_file.read(magic, 64);

    for (int i = 0; i<64; i++)
    {
         printf("%u ",magic[i]);
    }
   
    printf("\n");
}


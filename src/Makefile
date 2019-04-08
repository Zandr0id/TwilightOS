#NOTE: $< is right of the :, and $@ is the left

OBJS_DIR=../objects
OBJ=boot_utils.o kernel_func.o#any .o file in the objects folder

#DEPS = any H files later on


#The compiler and its flags
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c

#If I ever want to use C++
#CC = ~/opt/cross_compiler/bin/i686-elf-g++
#CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

#Linker Flags
LDFLAGS = -T link.ld -ffreestanding -O2 -lgcc -nostdlib

#The assembler and its flags
ASM = nasm
ASMFLAGS = -felf32

#GCC assembler flags
CASM=i686-elf-as

all : kernel.bin

kernel.bin : boot_utils.o kernel_func.o	vga_controller.o
	$(CC) $(LDFLAGS) boot_utils.o kernel_func.o vga_controller.o -o kernel.bin

# assemble any .asm files and put them in the OBJS_DIR
boot_utils.o : boot_utils.asm
	$(ASM) $(ASMFLAGS) $< -o $@

#compile any .c files and put them in the OBJS_DIR
vga_controller.o: vga_controller.c vga_controller.h
	$(CC) $(CFLAGS) $< -o $@

kernel_func.o : kernel_func.c
	$(CC) $(CFLAGS) $< -o $@


# assemble any .asm files and put them in the OBJS_DIR
#%.o : %.asm
#	$(ASM) $(ASMFLAGS) $< -o $@ 

#compile any .c files and put them in the OBJS_DIR
#%.o : %.c
#	$(CC) $(CFLAGS) $< -o $@

#kernel.bin : $(OBJ)
#	$(CC) $(LINKFLAGS) $< -o $@


#.PHONY tells make that there will never be file called clean
.PHONY: clean 

clean:
	rm -f *.o *~ core *.bin

	
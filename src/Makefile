#NOTE: $@ is right of the :, and $< is the left

#any .o file in the objects folder
OBJS_DIR = ../objects

#find every file with a .c or .asm
SRC_FILES := $(wildcard  *.asm) $(wildcard *.c)
#strip the suffix and append .o onto it
OBJ := $(addsuffix .o, $(basename $(SRC_FILES)))

#This is what the output file will be called
OUTPUT_FILE = kernel.bin

#The compiler and its flags
CC = i686-elf-gcc
CFLAGS = -c -std=gnu17 -ffreestanding -O2 -Wall -Wextra

#If I ever want to use C++
#CC = ~/opt/cross_compiler/bin/i686-elf-g++
#CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

#Linker Flags
LDFLAGS = -T link.ld -ffreestanding -O2 -lgcc -nostdlib

#The assembler and its flags
ASM = nasm
ASMFLAGS = -felf32

#GCC assembler does not need flags
#ASM=i686-elf-as

all : $(OUTPUT_FILE)

$(OUTPUT_FILE) : $(OBJ)
	@$(CC) $(LDFLAGS) $(OBJ) -o $(OUTPUT_FILE)
	@echo "Linking $(OBJ) ----------> $@"

# assemble any .asm files and put them in the OBJS_DIR
%.o : %.asm
	@$(ASM) $(ASMFLAGS) $< -o $@
	@echo "$<  ----->  $@"
#compile any .c files and put them in the OBJS_DIR

%.o : %.c 
	@$(CC) $(CFLAGS) $< -o $@
	@echo "$<  ----->  $@"

files: 
	@echo $(SRC_FILES)

#.PHONY tells make that there will never be file called clean
.PHONY: clean 

clean:
	@echo "Clean up..."
	rm -f *.o *~ *.bin

	
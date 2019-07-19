#NOTE: $@ is right of the :, and $< is the left

#locations of files
OBJS_DIR = ../objects # .o files
BIN_DIR = ../bin # .bin files
SRC_DIR = . # source files and the make file

#find every file with a .c or .asm
SRC_FILES := $(wildcard  *.asm) $(wildcard *.c) $(wildcard *.cpp)
#strip the suffix and append .o onto it
OBJ := $(addsuffix .o, $(basename $(SRC_FILES)))

#This is what the output file will be called
OUTPUT_FILE = kernel.bin

#The compiler and its flags
CC = i686-elf-gcc
CFLAGS = -c -std=gnu17 -ffreestanding -O2 -Wall -Wextra

#If I ever want to use C++
#CPP = ~/opt/cross_compiler/bin/i686-elf-g++
#CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

#Linker Flags
LDFLAGS = -T ../src/link.ld -ffreestanding -O2 -lgcc -nostdlib

#The assembler and its flags
ASM = nasm
ASMFLAGS = -felf32

#GCC assembler does not need flags
#ASM=i686-elf-as

.ONESHELL: # this lets everything be run in one shell, so things like "cd" work as expected

build : $(OUTPUT_FILE)
$(OUTPUT_FILE) : $(OBJ)
	@cd $(OBJS_DIR) 
	@$(CC) $(LDFLAGS) $(OBJ) -o $(OUTPUT_FILE)
	@echo "Linking $(OBJ) ----------> $@"
	@mv $@ $(BIN_DIR)

# assemble any .asm files and put them in the OBJS_DIR
%.o : %.asm
	@$(ASM) $(ASMFLAGS) $< -o $@
	@echo "$<  ----->  $@"
	@mv $@ $(OBJS_DIR)

#compile any .c files and put them in the OBJS_DIR

%.o : %.c 
	@$(CC) $(CFLAGS) $< -o $@
	@echo "$<  ----->  $@"
	@mv $@ $(OBJS_DIR)

files: 
	@echo $(SRC_FILES)

#.PHONY tells make that there will never be file called clean
.PHONY: clean print run all list

list:
	@echo "list    ---> list all options"
	@echo "build   ---> build any changes"
	@echo "clean   ---> remove all compiled files"
	@echo "rebuild ---> clean, then build"
	@echo "run     ---> run virtual test"
	@echo "all     ---> clean, build, then run"
	@echo "files   ---> show what files will be used when building"
	@echo "print   ---> prints a sick message"

rebuild:
	@make print
	@make clean
	@make build
	@echo "Full Clean and Make done..."

all:
	@make rebuild
	@make run

clean:
	@echo "Clean up..."
	@cd $(OBJS_DIR)
	@rm -f *.o *~
	@cd $(BIN_DIR)
	@rm -f *~ *.bin

print:
	@echo ""
	@echo ""
	@echo "     CCCCCCCCCCC                                           OOOOOOOOOOO             SSSSSSSSSSSS    "
	@echo "   CCCCCCCCCCCCCCC                                      OOOOOOOOOOOOOOOOO        SSSSSSSSSSSSSSSS  "
	@echo " CCCCC         CCCCC   hhh                           OOOOOO           OOOOOO    SSSSSS      SSSSSS "              
	@echo "CCCCC           CCCCC  hhh                          OOOOOO             OOOOOO  SSSSSS        SSSSSS"
	@echo "CCCCC                  hhh                          OOOOOO             OOOOOO    SSSSSSS           "
	@echo "CCCCC                  hhh            aaaaaa  aaa   OOOOOO             OOOOOO       SSSSSSSS       "
	@echo "CCCCC                  hhh           aaa  aaa aaa   OOOOOO             OOOOOO           SSSSSSS    "
	@echo "CCCCC                  hhh hhhh     aaa     aaaaa   OOOOOO             OOOOOO               SSSSSS "
	@echo "CCCCC           CCCCC  hhhhhhhhhh   aaa      aaaa   OOOOOO             OOOOOO  SSSSSS        SSSSSS"
	@echo " CCCCC         CCCCC   hhh     hhh  aaa     aaaaa    OOOOOO           OOOOOO    SSSSSS      SSSSSS "
	@echo "   CCCCCCCCCCCCCCC     hhh     hhh   aaa  aaa aaa       OOOOOOOOOOOOOOOOO        SSSSSSSSSSSSSSSS  "
	@echo "      CCCCCCCCCC       hhh     hhh    aaaaaa  aaaaa        OOOOOOOOOOO             SSSSSSSSSSSS    "
	@echo ""
	@echo ""
	

run:
	@echo "Starting QEMU"
	@powershell.exe start ../scripts/run_qemu.bat
#NOTE: $@ is right of the :, and $< is the left
MAKEFLAGS = -s #silent

#locations of files
OBJS_DIR := ./objects
BIN_DIR := ./bin
SRC_DIR := ./src/kernel
INCLUDE_DIR := ./src/include

#This project is made of .asm and .cpp files
#Go into the SRC_DIR and lookd for any of those.
#each file type needs to be located separatly because duplicate
#names will mess up the search if I try to do it in one command

ASM_SRC_FILES := $(wildcard $(SRC_DIR)/*.asm) $(wildcard $(SRC_DIR)/*/*.asm) $(wildcard $(SRC_DIR)/*/*/*.asm)
CPP_SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)
C_SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c)

#Put all the files together in one list
#This is now a single list of every file that needs to be compiled together
SRC_FILES := $(ASM_SRC_FILES) $(C_SRC_FILES) $(CPP_SRC_FILES) 

#strip the SRC_DIR/*.sufix and change to OBJ_DIR/*.o
#After this, every file with .asm, .c, etc. now has a .o
#This assumes for now that every file in the project is going into the same final output file
#When I start building multiple output files, this will have to change somehow

#OBJ_FILES := $($(notdir $(SRC_FILES)), $(OBJS_DIR), $(addsuffix .o, $(basename $(SRC_FILES))))
OBJ_FILES := $(subst $(SRC_DIR), $(OBJS_DIR), $(addsuffix .o, $(basename $(SRC_FILES))))
#OBJ_FILES := $(OBJS_DIR)/asm.o $(OBJS_DIR)/cpp.o $(OBJS_DIR)/c.o

#This is what the output file will be called
OUTPUT_FILE = $(BIN_DIR)/kernel.bin

#flags used by both compilers
COMMON_FLAGS = -c -O2 -ffreestanding -lgcc -fno-pic -Werror -Wall -Wextra -I$(INCLUDE_DIR)

#The compiler and its flags
CC = i686-elf-gcc
CFLAGS = -std=gnu17 $(COMMON_FLAGS)

#If I ever want to use C++
CPP = i686-elf-c++
CPPFLAGS = -fno-exceptions -std=c++17 $(COMMON_FLAGS) -fno-rtti

#Linker Flags
LDFLAGS = -T link.ld -ffreestanding -O2 -lgcc -nostdlib

#The assembler and its flags
ASM = nasm
ASMFLAGS = -felf32

#GCC assembler does not need flags
#ASM=i686-elf-as

#.ONESHELL: # this lets everything be run in one shell, so things like "cd" work as expected

build : $(OUTPUT_FILE)

$(OUTPUT_FILE) : $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $(OUTPUT_FILE)
	echo "Linking $(OBJ_FILES) ----------> $@"

# assemble any .asm files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.asm
	mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@
	echo "$<  ----->  $@"

#compile any .c files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
	echo "$<  ----->  $@"

#compiile and .cpp files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.cpp 
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< -o $@
	echo "$<  ----->  $@"

files: 
	echo "<----- .asm ----->"
	echo $(ASM_SRC_FILES) "\n"
	echo "<----- .c ----->"
	echo $(C_SRC_FILES) "\n"
	echo "<----- .cpp ----->"
	echo $(CPP_SRC_FILES)  "\n"
	echo "<----- objects ----->"
	echo $(OBJ_FILES) "\n"
	echo "<----- Output File ----->"
	echo $(OUTPUT_FILE)

#.PHONY tells make that there will never be these files
.PHONY: clean print run all list files

list:
	echo "list    ---> list all options"
	echo "build   ---> build any changes"
	echo "clean   ---> remove all compiled files"
	echo "rebuild ---> clean, then build"
	echo "run     ---> run virtual test"
	echo "all     ---> clean, build, then run"
	echo "files   ---> show what source files will be used when building"
	echo "print   ---> prints a sick message"

rebuild: print clean build
	echo "Full Clean and Make done..."

all: rebuild run

clean:
	echo "Clean up..."
	rm -rf $(OBJS_DIR)

	rm -f $(BIN_DIR)/*~ $(BIN_DIR)/*.bin

print:
	# don't fail if figlet isn't installed
	if which figlet >/dev/null; then figlet -c Twilight; else echo "                        ##### Twilight #####"; fi
	
run:
	echo "Starting QEMU"
	#qemu-system-i386 -kernel $(OUTPUT_FILE) -serial stdio
	cmd.exe /C "scripts\run_qemu.bat"


#NOTE: $@ is right of the :, and $< is the left
MAKEFLAGS = -s #silent

#locations of files
OBJS_DIR := ./objects
BIN_DIR := ./bin
SRC_DIR := ./src/kernel
INCLUDE_DIR := ./src/include

#This project is made of .asm, .c, and possibly .cpp files
#Go into the SRC_DIR and lookd for any of those.
#each file type needs to be located separatly because duplicate
#names will mess up the search if I try to do it in one command
ASM_SRC_FILES := $(wildcard  $(SRC_DIR)/*.asm) 
C_SRC_FILES := $(wildcard $(SRC_DIR)/*.c) 
#CPP_SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

#Put all the files together in one list
#This is now a single list of every file that needs to be compiled together
SRC_FILES := $(ASM_SRC_FILES) $(C_SRC_FILES) #$(CPP_SRC_FILES) 

#strip the SRC_DIR/*.sufix and change to OBJ_DIR/*.o
#After this, every file with .asm, .c, etc. now has a .o
#This assumes for now that every file in the project is going into the same final output file
#When I start building multiple output files, this will have to change somehow
OBJ_FILES := $(subst $(SRC_DIR), $(OBJS_DIR), $(addsuffix .o, $(basename $(SRC_FILES))))

#This is what the output file will be called
OUTPUT_FILE = $(BIN_DIR)/kernel.bin


#flags used by both compilers
COMMON_FLAGS = -c -O2 -ffreestanding -lgcc -Werror -Wall -Wextra -l$(INCLUDE_DIR)

#The compiler and its flags
CC = i686-elf-gcc
CFLAGS = -std=gnu17 $(COMMON_FLAGS)

#If I ever want to use C++
CPP = i686-elf-c++
CPPFLAGS = -ffreestanding -fno-exceptions $(COMMON_FLAGS) #-fno-rtti

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
	#@cd $(OBJS_DIR) 
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $(OUTPUT_FILE)
	echo "Linking $(OBJ_FILES) ----------> $@"

# assemble any .asm files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.asm
	$(ASM) $(ASMFLAGS) $< -o $@
	echo "$<  ----->  $@"

#compile any .c files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) $< -o $@
	echo "$<  ----->  $@"

#compiile and .cpp files and put them in the OBJS_DIR
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(CPP) $(CPPFLAGS) $< -o $@
	echo "$<  ----->  $@"

files: 
	echo "<----- .asm ----->"
	echo $(ASM_SRC_FILES) "\n"
	echo "<----- .c ----->"
	echo $(C_SRC_FILES) "\n"
	#echo "_______.cpp________"
	#echo $(CPP_SRC_FILES)  "\n"
	echo "<----- objects ----->"
	echo $(OBJ_FILES) "\n"
	echo "<----- Output File ----->"
	echo $(OUTPUT_FILE)

#.PHONY tells make that there will never be file called clean
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
	rm -f $(OBJS_DIR)/*.o $(OBJS_DIR)/*~
	rm -f $(BIN_DIR)/*~ $(BIN_DIR)/*.bin

print:
	figlet -c ChaOS -f banner
	
run:
	echo "Starting QEMU"
	qemu-system-i386 -kernel $(OUTPUT_FILE)
	#powershell.exe start scripts/run_qemu.bat


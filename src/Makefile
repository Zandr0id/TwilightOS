MAKEFLAGS = -s

OBJS_DIR := ../objects
BIN_DIR := ../bin
SRC_DIR := ./kernel
INCLUDE_DIR := ./include

ASM_SRC_FILES := $(wildcard $(SRC_DIR)/*.asm) $(wildcard $(SRC_DIR)/*/*.asm) $(wildcard $(SRC_DIR)/*/*/*.asm)
CPP_SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)
C_SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c)

SRC_FILES := $(ASM_SRC_FILES) $(C_SRC_FILES) $(CPP_SRC_FILES)

OBJ_FILES := $(subst $(SRC_DIR), $(OBJS_DIR), $(addsuffix .o, $(basename $(SRC_FILES))))

OUTPUT_FILE = $(BIN_DIR)/kernel.bin

COMMON_FLAGS = -g -c -O0 -ffreestanding -lgcc -fno-pic -Werror -Wall -Wextra -I$(INCLUDE_DIR)

CC = i686-elf-gcc
CFLAGS = -std=gnu17 $(COMMON_FLAGS)

CPP = i686-elf-c++
CPPFLAGS = -fno-exceptions -std=c++17 $(COMMON_FLAGS) -fno-rtti

LDFLAGS = -T ../link.ld -ffreestanding -O0 -lgcc -nostdlib

ASM = nasm
ASMFLAGS = -felf32 -F dwarf -g

CRTBEGIN_OBJ:=$(shell $(CPP) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CPP) -print-file-name=crtend.o)

build : $(OUTPUT_FILE)

$(OUTPUT_FILE) : $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $(OUTPUT_FILE)
	echo "Linking $(OBJ_FILES) $(CRTEND_OBJ) $(CRTEND_OBJ) ----------> $@"

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.asm
	mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@
	echo "$<  ----->  $@"

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
	echo "$<  ----->  $@"

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

.PHONY:

list:
	echo "list    ---> list all options"
	echo "build   ---> build any changes"
	echo "clean   ---> remove all compiled files"
	echo "rebuild ---> clean, then build"
	echo "run     ---> run virtual test"
	echo "all     ---> clean, build, then run"
	echo "files   ---> show what source files will be used when building"
	echo "print   ---> prints a sick message

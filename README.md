# ChaOS
----
This is a project that is intended to become my every day use OS. I want to learn how to make the tools that I use everyday. It's still in the very first stages, but there are promising resultes so far. It's going to be somewhat POSIX complient so porting software is possible, and it will have some unix-likeness to it. The future plan is to use it as a base to develope standalone applications for it, like a code IDE and web browser. Perhaps even a complier or language interpreter. 

## Building
----
For now, ChaOS is built using the cross compiler described in the [OSDev.org Cross Compiler](https://wiki.osdev.org/GCC_Cross-Compiler) section. I'm using Visual Studio Code as the main editor and doing the compiling with the Windows Subsystem for Linux. I've only done testing on Qemu and VirtualBox, but you can try any emulator you want. You'll have to change the path in the `make run` recipe to use what you want if you want to use that command.

## **Some useful makefile commands**
----
Check out the make file to see all the options, but these are the most useful
- `make clean` will clean all built files
- `make build` will build all files
- `make run` will start the OS with Qemu
- `make files` will show you every file that is located for use in building process

## **Goals**
----
This isn't a strict order, but makes sense as a logical progression.
- [x] Be able to boot
- [x] Display text to the screen
- [x] GDT
- [x] IDT
- [x] Exceptions
- [x] System clock
  - [x] Keep time
  - [ ] Delay/Sleep functions
- [x] Keyboard Support
- [ ] Dynamic Memory
  - [ ] malloc, heap
- [ ] File System
  - [ ] ext2
  - [ ] VFS
- [ ] Graphics
  - [ ] GUI library


## **Problems**
----
#### Code
- Sometimes key presses are not detected. Should investigate.
- vga_controler.c needs rework. The indexing on the screen is all messed up.
#### Theory
- Organize file structure better
  * Separate CPU based things
  * Look at POSIX libC
- Decide on Makefile process
  * Can't decide what is better. Single make file, or individual Makefiles per folder of source
- Project name. I like ChaOS, but TwilightOS was also suggested and that's kind of pretty...
  
## **Screen Shots**
----
![Latest Screenshot](/images/Keyboard_Input.png)

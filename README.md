# TwilightOS
----
This is a project that is intended to become my every day use OS. I want to learn how to make the tools that I use everyday. It's still in the very first stages, but there are promising resultes so far. I'm not going for a Unix clone, but I will include Unix design choices that I think are good ones, and there will be just enough POSIX compliance to port some software. The future plan is to use it as a base to develope standalone applications for it, like a code IDE and web browser. Perhaps even a complier or language interpreter.

## Design Philosophy
----
This OS is for me, but I'd love for others to help and use it as well. I want Twilight to be approchable and understandable to anyone looking at it for the first time. With that in mind, I'm making a conscious effort to make things readable and not do anything too fancy. Even though it probably affects performance, I'm valuing maintainability as a higher priority. I'd also prefer to be the one to add any major features, since this is primarily a learining excersise for me. If you have a large feature that would like to add, please talk to me about it first. I'm really only interesting in having functionality that I would personally use.

## Building
----
For now, Twilight is built using the cross compiler described in the [OSDev.org Cross Compiler](https://wiki.osdev.org/GCC_Cross-Compiler) section, and NASM. I'm using Visual Studio Code as the main editor and doing the compiling with the Windows Subsystem for Linux, but standalone linux works fine too. I've only done testing on Qemu and VirtualBox. You'll have to change the path in the `make run` recipe to perform testing in the manner that you want.

## **Some useful makefile commands**
----
Check out the make file to see all the options, but these are the most useful
- `make clean` will clean all built files
- `make build` will build all files
- `make run` will start the OS with Qemu
- `make files` will show you every file that is located for use in building process

## **Goals**
----
This isn't a strict order, but makes sense as a logical progression. Look in the wiki for more detail about what is already in.
- [x] Be able to boot
- [x] Display text to the screen
- [x] GDT
- [x] IDT
- [x] Exceptions
- [x] System clock
  - [x] Keep time
  - [ ] Delay/Sleep functions
- [x] Keyboard Support
- [x] Dynamic Memory
  - [x] malloc()
  - [x] heap
  - [x] free()
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
  
## **Current Screenshot**
----
![Latest Screenshot](/images/Keyboard_Input.PNG)

## **Contributors**
----
- Zane Youmans

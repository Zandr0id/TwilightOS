# ChaOS
Experimental operating system from the ground up.
This is a personal project. Perhaps I'll open it up to others if it gets anywhere.

This is built using the cross compiler described in https://wiki.osdev.org/GCC_Cross-Compiler
The make file has a number of useful options, however, you'll want to change the Make run to point to wherever you have qemu installed.
I'm developing this on windows with WLS, so qemu must be started in a hacky way with windows.

Make clean - clean all build files
Make deploy - build and run
Make all - rebuild all files

Goals
1. Be able to boot -DONE
2. Display text to the screen -DONE
3. GTD -Done
4. IDT -Not working yet
5. Accept keyboard input
6. File System
7. Graphics

Problems
IDT does not seem to be working. Exceptions cause a triple fault


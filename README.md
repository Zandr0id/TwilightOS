# ChaOS
Experimental operating system from the ground up. I want to learn about what's going on *"under the hood"* and this would be a good way to do it. It is built using the cross compiler described in the [OSDev.org Cross Compiler](https://wiki.osdev.org/GCC_Cross-Compiler) section.

The make file has a number of useful options, however, you'll want to change the `make run` to point to wherever you have qemu installed.
I'm developing this on windows with WLS, so qemu must be started in a hacky way with a windows powershell.

## **Some useful makefile commands**
Check out the make file to see all the options, but these are the most useful
- `make clean` will clean all built files
- `make all` will build all files
- `make run` will start the OS with Qemu
- `make deploy` will do all of the above in one step


## **Goals**
- [x] Be able to boot
- [x] Display text to the screen
- [x] GTD
- [ ] IDT
- [ ] Keyboard Support
- [ ] File System
- [ ] Graphics


## **Problems**
- [ ] IDT does not seem to be working. Exceptions cause a triple fault
- [ ] Library situation is very bad. Everything is in syslib. Need to reorganize


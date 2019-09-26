# ChaOS
Experimental operating system from the ground up.
This is a personal project. Perhaps I'll open it up to others if it gets anywhere.

This is built using the cross compiler described in the [OSDev Cross Compiler](https://wiki.osdev.org/GCC_Cross-Compiler) section.

The make file has a number of useful options, however, you'll want to change the Make run to point to wherever you have qemu installed.
I'm developing this on windows with WLS, so qemu must be started in a hacky way with windows.

## **Some useful makefile commands**
```
make run
make all
make deploy
```

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


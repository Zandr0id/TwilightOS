[BITS 32] ;32 bit protected mode
GLOBAL start ; start is the entry point

start:
    mov esp, _stack_top ;move the stack pointer to where I want it
    jmp stublet ;jump down to the portion that does most of the actual work


;The multiboot header is used by grub to detect an OS
;not totally sure what everything means yet, but i'll just get it working and not worry about it for right now.

ALIGN 4 ;this moves us to the next 4 btye section of memory
multi_boot:

    ;These are just declaring macros
    MULTIBOOT_PAGE_ALIGN    equ 1<<0 ;set some bits that are required
    MULTIBOOT_MEMORY_INFO   equ 1<<1
    MULTIBOOT_AOUT_KLUDG    equ 1<<16
    MULTIBOOT_HEADER_MAGIC  equ 0x1BADB002
    
    ;OR them all together to make some more macros
    MULTIBOOT_HEADER_FLAGS  equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDG
    MULTIBOOT_CHECKSUM      equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

    EXTERN code, bss, end ;these portions will be defined by the linker script

    ;this is actually setting the data into memory
    dd MULTIBOOT_HEADER_MAGIC ;magic number goes first so GRUB will recognize the OS
    dd MULTIBOOT_HEADER_FLAGS ;flags come next
    dd MULTIBOOT_CHECKSUM ;checksum at the end

    dd multi_boot
    dd code
    dd bss
    dd end
    dd start

stublet:
    ;make the call to main right here!!!
    extern kernel_main ;kernel_main is defined in another file
    call kernel_main ;CALL THAT KERNEL!!!

    jmp $ ;endless loop

SECTION .bss
ALIGN 16
_stack_bot:
    resb 16834 ;reserving an 16K stack
_stack_top: ;the stack grows backwards, so the "top" is actually set at the end
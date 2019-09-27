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

    ; code for loading GDT
    global gdt_flush
    extern gdt_ptr
    gdt_flush:
        lgdt [gdt_ptr]
        mov ax, 0x10
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ss, ax
        jmp 0x08:flush2
    flush2:
        ret

    ; code for loading interrupts
    global idt_load
    extern idt_ptr

    extern test_msg ;just prints STOP so I can see what is executing

    idt_load:
        lidt[idt_ptr]
        ret

    ; actual ISR function calls
    global isr0
    global isr1
    global isr2
    global isr3
    global isr4
    global isr5
    global isr6
    global isr7
    global isr8
    global isr9
    global isr10
    global isr11
    global isr12
    global isr13
    global isr14
    global isr15
    global isr16
    global isr17
    global isr18
    global isr19
    global isr20
    global isr21
    global isr22
    global isr23
    global isr24
    global isr25
    global isr26
    global isr27
    global isr28
    global isr29
    global isr30
    global isr31

    ;if an ISR does not provide an error code on it's own, just push a 0 to the stack to keep them all the same
    isr0: ;divide by 0 exception
        push byte 0 ; a dummy error code
        push byte 0 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr1: ;Debug exception
        push byte 0 ; a dummy error code
        push byte 1 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr2: ;non maskable interrupt exception
        push byte 0 ; a dummy error code
        push byte 2 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr3: ;Breakpoint exception
        push byte 0 ; a dummy error code
        push byte 3 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr4: ;Into Detected Overflow exception
        push byte 0 ; a dummy error code
        push byte 4 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr5: ;Out Of bounds exception
        push byte 0 ; a dummy error code
        push byte 5 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr6: ;Invalide Opcode exception
        push byte 0 ; a dummy error code
        push byte 6 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr7: ;No Coprocessor exception
        push byte 0 ; a dummy error code
        push byte 7 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr8: ;Double Fault exception. Already pushes a fault code
        push byte 8 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr9: ;Coprocessor Segment Overrun Exception
        push byte 0 ; a dummy error code
        push byte 9 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr10: ;Bad TSS exception. Already pushes a fault code
        push byte 10 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr11: ;Segment Not Present Exception. Already pushes a fault code
        push byte 11 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr12: ;Stack Fault Exception. Already pushes a fault code
        push byte 12 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr13: ;General Protection Fault Exception. Already pushes a fault code
        push byte 13 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr14: ;Page Fault Exception. Already pushes a fault code
        push byte 14 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr15: ;Unknown Interrupt Exception
        push byte 0 ; a dummy error code
        push byte 15 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr16: ;Coprocessor Fault Exception
        push byte 0 ; a dummy error code
        push byte 16 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr17: ;Alignment Check Exception
        push byte 0 ; a dummy error code
        push byte 17 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr18: ;Machine Check Exception
        push byte 0 ; a dummy error code
        push byte 18 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr19: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 19 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr20: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 20 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr21: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 21 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr22: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 22 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr23: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 23 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr24: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 24 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr25: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 25 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr26: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 26 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr27: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 27 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr28: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 28 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr29: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 29 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr30: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 30 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs
    isr31: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 31 ; which exeption it is
        jmp isr_common_stub ; a common function for all ISRs

    extern fault_handler

    isr_common_stub: ; the place all ISRs will jump to
        pusha
        push ds
        push es
        push fs
        push gs
        mov ax, 0x10   ; Load the Kernel Data Segment descriptor!
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov eax, esp   ; Push us the stack pointer
        push eax
        mov eax, fault_handler
        call eax       ; A special call, preserves the 'eip' register
        pop eax
        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8     ; Cleans up the pushed error code and pushed ISR number
        iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP!

SECTION .bss
ALIGN 16
_stack_bot:
    resb 16834 ;reserving an 16K stack
_stack_top: ;the stack grows backwards, so the "top" is actually set at the end
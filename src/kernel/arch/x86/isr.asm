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

    global irq0
    global irq1
    global irq2
    global irq3
    global irq4
    global irq5
    global irq6
    global irq7
    global irq8
    global irq9
    global irq10
    global irq11
    global irq12
    global irq13
    global irq14
    global irq15
    

    ;if an ISR does not provide an error code on it's own, just push a 0 to the stack to keep them all the same
    isr0: ;divide by 0 exception
        push byte 0 ; a dummy error code
        push byte 0 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr1: ;Debug exception
        push byte 0 ; a dummy error code
        push byte 1 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr2: ;non maskable interrupt exception
        push byte 0 ; a dummy error code
        push byte 2 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr3: ;Breakpoint exception
        push byte 0 ; a dummy error code
        push byte 3 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr4: ;Into Detected Overflow exception
        push byte 0 ; a dummy error code
        push byte 4 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr5: ;Out Of bounds exception
        push byte 0 ; a dummy error code
        push byte 5 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr6: ;Invalide Opcode exception
        push byte 0 ; a dummy error code
        push byte 6 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr7: ;No Coprocessor exception
        push byte 0 ; a dummy error code
        push byte 7 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr8: ;Double Fault exception. Already pushes a fault code
        push byte 8 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr9: ;Coprocessor Segment Overrun Exception
        push byte 0 ; a dummy error code
        push byte 9 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr10: ;Bad TSS exception. Already pushes a fault code
        push byte 10 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr11: ;Segment Not Present Exception. Already pushes a fault code
        push byte 11 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr12: ;Stack Fault Exception. Already pushes a fault code
        push byte 12 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr13: ;General Protection Fault Exception. Already pushes a fault code
        push byte 13 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr14: ;Page Fault Exception. Already pushes a fault code
        push byte 14 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr15: ;Unknown Interrupt Exception
        push byte 0 ; a dummy error code
        push byte 15 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr16: ;Coprocessor Fault Exception
        push byte 0 ; a dummy error code
        push byte 16 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr17: ;Alignment Check Exception
        push byte 0 ; a dummy error code
        push byte 17 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr18: ;Machine Check Exception
        push byte 0 ; a dummy error code
        push byte 18 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr19: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 19 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr20: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 20 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr21: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 21 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr22: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 22 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr23: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 23 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr24: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 24 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr25: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 25 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr26: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 26 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr27: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 27 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr28: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 28 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr29: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 29 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr30: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 30 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    isr31: ;Reserved Exception
        push byte 0 ; a dummy error code
        push byte 31 ; which exeption it is
        jmp exception_common_stub ; a common function for all ISRs
    
    irq0: 
        push byte 0
        push byte 32
        jmp irq_common_stub
    irq1:
        push byte 1
        push byte 33
        jmp irq_common_stub
    irq2: 
        push byte 2
        push byte 34
        jmp irq_common_stub
    irq3:
        push byte 3
        push byte 35
        jmp irq_common_stub
    irq4:
        push byte 4
        push byte 36
        jmp irq_common_stub
    irq5: 
        push byte 5
        push byte 37
        jmp irq_common_stub
    irq6: 
        push byte 6
        push byte 38
        jmp irq_common_stub
    irq7:
        push byte 7
        push byte 39
        jmp irq_common_stub
    irq8: 
        push byte 8
        push byte 40
        jmp irq_common_stub
    irq9:
        push byte 9
        push byte 41
        jmp irq_common_stub
    irq10:
        push byte 10
        push byte 42
        jmp irq_common_stub
    irq11: 
        push byte 11
        push byte 43
        jmp irq_common_stub
    irq12:
        push byte 12
        push byte 44
        jmp irq_common_stub
    irq13: 
        push byte 13
        push byte 45
        jmp irq_common_stub
    irq14: 
        push byte 14
        push byte 46
        jmp irq_common_stub
    irq15: 
        push byte 15
        push byte 47
        jmp irq_common_stub

    extern fault_handler
    extern irq_handler

    extern TEST_MSG

    exception_common_stub: ; the place all ISRs will jump to
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

    irq_common_stub:
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
        mov eax, irq_handler
        ;call TEST_MSG
        call eax       ; A special call, preserves the 'eip' register
        pop eax
        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8     ; Cleans up the pushed error code and pushed ISR number
        iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP!
    ; code for loading interrupts descriptor table
    global idt_load
    extern idt_ptr

    idt_load:
        lidt[idt_ptr]
        sti
        ret
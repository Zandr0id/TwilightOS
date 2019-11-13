
#include <libc/stdlib.h>
#include <libc/syslib.h>
#include <libc/stdio.h>
#include <arch/x86/isr_helper.h>

isr_t interrupt_handlers[256];
//static Debug_Logger * logger = Debug_Logger::Instance();

void register_interrupt_handler(int n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}

//TODO: Remove this eventually
void TEST_MSG()
{
    printf("TEST\n\0");
}

//links each ISR number with it's respctive function
void isr_install()
{
    //Exception handlers
    printf("Install ISR\n");
    idt_add_entry(0, (unsigned)isr0, 0x08, 0x8E);
    idt_add_entry(1, (unsigned)isr1, 0x08, 0x8E);
    idt_add_entry(2, (unsigned)isr2, 0x08, 0x8E);
    idt_add_entry(3, (unsigned)isr3, 0x08, 0x8E);
    idt_add_entry(4, (unsigned)isr4, 0x08, 0x8E);
    idt_add_entry(5, (unsigned)isr5, 0x08, 0x8E);
    idt_add_entry(6, (unsigned)isr6, 0x08, 0x8E);
    idt_add_entry(7, (unsigned)isr7, 0x08, 0x8E);
    idt_add_entry(8, (unsigned)isr8, 0x08, 0x8E);
    idt_add_entry(9, (unsigned)isr9, 0x08, 0x8E);
    idt_add_entry(10, (unsigned)isr10, 0x08, 0x8E);
    idt_add_entry(11, (unsigned)isr11, 0x08, 0x8E);
    idt_add_entry(12, (unsigned)isr12, 0x08, 0x8E);
    idt_add_entry(13, (unsigned)isr13, 0x08, 0x8E);
    idt_add_entry(14, (unsigned)isr14, 0x08, 0x8E);
    idt_add_entry(15, (unsigned)isr15, 0x08, 0x8E);
    idt_add_entry(16, (unsigned)isr16, 0x08, 0x8E);
    idt_add_entry(17, (unsigned)isr17, 0x08, 0x8E);
    idt_add_entry(18, (unsigned)isr18, 0x08, 0x8E);
    idt_add_entry(19, (unsigned)isr19, 0x08, 0x8E);
    idt_add_entry(20, (unsigned)isr20, 0x08, 0x8E);
    idt_add_entry(21, (unsigned)isr21, 0x08, 0x8E);
    idt_add_entry(22, (unsigned)isr22, 0x08, 0x8E);
    idt_add_entry(23, (unsigned)isr23, 0x08, 0x8E);
    idt_add_entry(24, (unsigned)isr24, 0x08, 0x8E);
    idt_add_entry(25, (unsigned)isr25, 0x08, 0x8E);
    idt_add_entry(26, (unsigned)isr26, 0x08, 0x8E);
    idt_add_entry(27, (unsigned)isr27, 0x08, 0x8E);
    idt_add_entry(28, (unsigned)isr28, 0x08, 0x8E);
    idt_add_entry(29, (unsigned)isr29, 0x08, 0x8E);
    idt_add_entry(30, (unsigned)isr30, 0x08, 0x8E);
    idt_add_entry(31, (unsigned)isr31, 0x08, 0x8E);

    //start of IRQs
    printf("Install IRQs\n");
    idt_add_entry(32, (unsigned)irq0, 0x08, 0x8E); //timer
    idt_add_entry(33, (unsigned)irq1, 0x08, 0x8E); //keyboard
    //TODO: perhaps catch ISR 2 and produce error?
    //idt_add_entry(34, (unsigned)irq2, 0x08, 0x8E); // This one should never be assigned
    idt_add_entry(35, (unsigned)irq3, 0x08, 0x8E); // COM 2
    idt_add_entry(36, (unsigned)irq4, 0x08, 0x8E); // COM 1
    idt_add_entry(37, (unsigned)irq5, 0x08, 0x8E); // LPT2
    idt_add_entry(38, (unsigned)irq6, 0x08, 0x8E); // Floppy disk
    //TODO: react to spurious irq 7
    idt_add_entry(39, (unsigned)irq7, 0x08, 0x8E); // LPT1/Spurious 
    idt_add_entry(40, (unsigned)irq8, 0x08, 0x8E); // CMOS real-time
    idt_add_entry(41, (unsigned)irq9, 0x08, 0x8E); // SCSI/NIC
    idt_add_entry(42, (unsigned)irq10, 0x08, 0x8E); // SCSI/NIC
    idt_add_entry(43, (unsigned)irq11, 0x08, 0x8E); // SCSI/NIC
    idt_add_entry(44, (unsigned)irq12, 0x08, 0x8E); // Mouse
    idt_add_entry(45, (unsigned)irq13, 0x08, 0x8E); // FPU
    idt_add_entry(46, (unsigned)irq14, 0x08, 0x8E); // Primary ATA
    idt_add_entry(47, (unsigned)irq15, 0x08, 0x8E); // Secondary ATA
}

void PIC_install()
{
    //program the PIC
    printf("Reprogramming PIC\n");
    outb(PIC0_CMD,0x11);
    outb(PIC1_CMD,0x11);
    outb(PIC0_DATA,0x20);
    outb(PIC1_DATA,0x28);
    outb(PIC0_DATA,0x04);
    outb(PIC1_DATA,0x02);
    outb(PIC0_DATA,0x01);
    outb(PIC1_DATA,0x01);

    //set all interrupts on
    //TODO: turn all of and turn on as needed
    outb(PIC0_DATA,0x0);
    outb(PIC1_DATA,0x0);
}

const char*exception_messages[] =
{
    "Divide By Zero exception\0",
    "Debug exception\0",
    "non maskable interrupt exception\0",
    "Breakpoint exception\0",
    "Into Detected Overflow exception\0",
    "Out Of bounds exception\0",
    "Invalide Opcode exception\0",
    "No Coprocessor exception\0",
    "Double Fault exception\0",
    "Coprocessor Segment Overrun Exception\0",
    "Bad TSS exception\0",
    "Segment Not Present Exception\0",
    "Stack Fault Exception\0",
    "General Protection Fault Exception\0",
    "Page Fault Exception\0",
    "Unknown Interrupt Exception\0",
    "Coprocessor Fault Exception\0",
    "Alignment Check Exception\0",
    "Machine Check Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0",
    "Reserved Exception\0"
};

extern "C"
{
void fault_handler(struct regs *r)
{
    printf("***EXCEPTION***\n");
    if (r->int_no < 32)
    {
        printf("%s\n",exception_messages[r->int_no]);
        printf("Error Code: %d\n",r->err_code);
        printf("Exeption Number: %d\n",r->int_no);
        printf("SYSTEM HALT...");
        while(true);
    }
    else
    {
        printf("Unknown Exception.....oops....");
    }
}

void irq_handler(struct regs * r)
{
    unsigned int irq_number = r->int_no;
    
    //acknowledge the PIC so it will send more interrupts
    if (irq_number >= 40)
    {
        outb(0xA0,0x20);
    }
    outb(0x20,0x20);

    if (interrupt_handlers[irq_number] != 0)
   {
       isr_t handler = interrupt_handlers[irq_number];
       handler(*r);
   }
}

}
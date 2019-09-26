
/* i'm pretty sure this script only looks for symbols and places them in memory the way thay've been outlind below */

OUTPUT_FORMAT("binary") /* the output file type is described here */
ENTRY(start) /* search for this symbol and make it the entry point */
phys = 0x00100000; /* the address to start at I guess? */
SECTIONS
{
    .text phys : AT(phys) /*place this at the starting memory location */
    { 
    code = .;
    *(.text)
    *(.rodata)
    . = ALIGN(4096);
    }
    .data : AT(phys + (data - code)) /* place this right after the code section */
    {
    data = .;
    *(.data)
    . = ALIGN(4096);
    }
    .bss : AT(phys + (bss - code))
    {
        bss = .;
        *(.bss)
        . = ALIGN(4096);
    }
    end = .;
}

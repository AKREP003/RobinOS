OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS
{
    . = 0x1000;   /* Set the load address */

    .text :
    {
        *(.text)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(COMMON)
        *(.bss)
    }
}


#include "../../stdlib/kernel_headers.h"

char KEY_READ = 0;

void read_key(void)
{
    unsigned char key;

    __asm__ volatile (
        "movb $1, %%ah\n\t"     // BIOS keyboard status
        "int $0x16\n\t"
                     // no key pressed

        "movb $0, %%ah\n\t"     // BIOS keyboard read
        "int $0x16\n\t"
        "movb %%al, %0\n\t"     // store key
        "jmp 2f\n\t"

        "1:\n\t"
        "movb $0, %0\n\t"       // no key

        "2:\n\t"
        : "=m"(KEY_READ)
        :
        : "eax"
    );
}

#include "../../stdlib/kernel_headers.h"

void print_char(char c)
{
    __asm__ volatile (
        "movb $0x0E, %%ah\n\t"
        "movb %0, %%al\n\t"
        "int $0x10\n\t"
        :
        : "r"(c)
        : "eax"
    );
}

void print_string(char* str)
{
    while (*str) {
        print_char(*str++);
    }
}

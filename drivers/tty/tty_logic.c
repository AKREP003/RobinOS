#include "../../stdlib/kernel_headers.h"


void print_inline(char* a){
    
    short size = str_size(a);

    char* buffer = (char*) alloc(size + 3);

    cpy((uintptr_t) buffer, (uintptr_t) a, size);

    buffer[size] = '\r';

    buffer[size + 1] = '\n';

    buffer[size + 2] = 0x0;

    print_string(buffer);

    free((uintptr_t) buffer);

}

void wake_up() {

}

#include "../../stdlib/kernel_headers.h"


void print_inline(char* a){
    
    int size = str_size(a);

    char* buffer = (char*) alloc(size + 3);

    cpy((int*) buffer, (int*) a, size);

    buffer[size] = '\r';

    buffer[size + 1] = '\n';

    buffer[size + 2] = 0x0;

    print_string(buffer);

    free((int) buffer);

}

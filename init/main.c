#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    char* chr = "abcefgthfsss";

    struct ll* linky = split_string(chr, 'f');

    print_string((char*) get_nth_element(linky, 2));

    print_string("\n no errors");
}




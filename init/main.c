#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    char* chr = "abc";

    struct ll* linky = as_string(chr);

    print_string((char*) get_nth_element(linky, 2));

    print_string("\n no errors");
}




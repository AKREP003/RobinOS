#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("well come to RobinOS!\n");
    
    char* res = (char*) alloc(100);

    char* it = itoa((int) res, res, 10);

    print_string("a");

    print_string(it);

    res = (char*) alloc(100);

    print_string("c");

    it = itoa((int) res, res, 10);

    print_string(it);

    print_string("b");

}




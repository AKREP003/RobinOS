#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    //file_system_init();

    struct ll* linky = new_ll(2);

    set_element_val(linky, (int*) "a");

    push(linky, (int*) "b");

    push(linky, (int*) "c");

    push(linky, (int*) "q");

    //print_string((char*) get_nth_element(linky, 2));

    print_ll(linky);

    //free_ll(linky);

    print_string("\n no errors");
}




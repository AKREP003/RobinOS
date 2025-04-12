#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    //file_system_init();

    struct ll* linky = new_ll(5);

    set_element_val(linky, (int*) "a");

    push(linky, (int*) "b");

    print_string((char*) get_nth_element(linky, 1));

    free_ll(linky);

    print_string("\n no errors");
}




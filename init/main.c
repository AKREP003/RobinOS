#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    file_system_init();

    char* data = "abb";

    write_to_file(15, (int*) data, 4);

    print_string("\n no errors");
}




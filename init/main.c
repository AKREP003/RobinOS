#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    file_system_init();

    char* data = "aaaz";

    write_to_file(25, (int*) data, str_size(data));

    data = "aaa";

    write_to_file(25, (int*) data, str_size(data));

    print_string((char*) read_file(25));

    print_string("\n no errors");
}




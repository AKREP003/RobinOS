#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    file_system_init();

    char* data = "abbwww";

    write_to_file(25, (int*) data, 7);

    print_string((char*) read_file(25));

    print_string("\n no errors");
}




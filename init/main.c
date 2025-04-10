#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    //create_file("a");

    int addr = 80;

    char* strin = (char*) alloc(512);

    char* second_string = "aaaa\n";

    cpy((int*) strin, (int*) second_string, str_size(second_string));

    disk_write(str_size(second_string), addr, (int) strin);

    char* strin2 = (char*) alloc(512);
    
    disk_read(str_size(second_string), addr, (int) strin2);

    print_string(strin2);

    print_string("no errors");
}




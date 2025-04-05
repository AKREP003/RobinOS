#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("well come to RobinOS!\n");
    
    

    char* stir = "aaa";
    
    print_string((char*) stir); 

    disk_write(512, 0x0, (int) stir);

    

    char* buffer = (char*) alloc(512);

    disk_read(512, 0x0, (int) buffer);

    print_string((char*) buffer); 

    
}




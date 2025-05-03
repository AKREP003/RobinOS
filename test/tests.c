#include "../stdlib/kernel_headers.h"

void print_test() {
    //print_string("prshort is working\n");
    //print_integer(69);
    //prtint_char('Q');
    
    print_inline("Tests initiate:");
    
}




void test_em_all() {
    print_test();

    if (!std_test())   {print_string("std functions failed\r\n");return;}

    print_string("std succ\r\n");

    if (!alloc_test()) {print_string("alloc failed\r\n");return;} 

    print_string("alloc succ\r\n");

    //wait_sec(5);

    if (!disk_test())  {print_string("disk failed");return;} 

    print_string("disk succ\r\n");

    //wait_sec(5);

    if (!file_system_test())  {print_string("file system failed");return;} 

    print_string("file system succ\r\n");

    //wait_sec(5);

    file_system_init();

    print_inline("file system initialised"); 

    if (!file_handling_test())  {print_string("file handling failed");return;} 

    print_string("file handling succ\r\n");

}    
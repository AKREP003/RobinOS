#include "../stdlib/kernel_headers.h"

void print_test() {
    //print_string("prshort is working\n");
    //print_integer(69);
    //prtint_char('Q');
    
    //print_inline("test");
    
}




void test_em_all() {
    print_test();

    if (!std_test())   {print_string("std functions failed\r\n");}

    print_string("std succ\r\n");

    wait_sec(5);

    if (!alloc_test()) {print_string("alloc failed\r\n");} 

    print_string("alloc succ\r\n");

    wait_sec(5);

    //if (!disk_test())  {print_string("disk failed");} 

    //print_string("disk succ");

    print_string("no errors\r\n");

}
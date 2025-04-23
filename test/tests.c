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

    wait_sec(1);

    if (!alloc_test()) {print_string("alloc failed\r\n");} 

    uintptr_t a = alloc(5);
    


    print_string("alloc succ\r\n");

    wait_sec(1);

    if (!disk_test())  {print_string("disk failed");} 

    print_string("disk succ\r\n");

    

    

}
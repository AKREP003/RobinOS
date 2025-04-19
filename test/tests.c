#include "../stdlib/kernel_headers.h"

void print_test() {
    //print_string("print is working\n");
    //print_integer(69);
    //prtint_char('Q');
    
    print_inline("test");
}




void test_em_all() {

    print_test();

    print_inline("c");

    if (!std_test())   {print_inline("std functions failed");}

    print_inline("std succ");

    if (!alloc_test()) {print_inline("alloc failed");} 

    print_inline("alloc succ");

    if (!disk_test())  {print_inline("disk failed");} 

    print_inline("disk succ");
    
    print_inline("no errors");

}
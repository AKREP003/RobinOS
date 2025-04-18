#include "../stdlib/kernel_headers.h"

void print_test() {
    //print_string("print is working\n");
    //print_integer(69);
    //prtint_char('Q');
    print_inline("abab");

    
    
    print_string("tes");
}




void test_em_all() {

    //print_test();

    if (!std_test())   {print_string("std functions failed");}

    if (!alloc_test()) {print_string("alloc failed");} 

    if (!disk_test())  {print_string("disk failed");} 

    print_string("\nno errors");

}
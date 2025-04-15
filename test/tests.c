#include "../stdlib/kernel_headers.h"

void print_test() {
    print_string("print is working\n");
    print_integer(69);
}


void test_em_all() {

    print_test();

    print_string("\nno errors");

}
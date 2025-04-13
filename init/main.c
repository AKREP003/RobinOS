#include "../stdlib/kernel_headers.h"


void aaa() {
    print_string("welcome to RobinOS!\n");
    
    char* chr = "a=26+f=28+d=2";

    struct ll* linky = parse_folder(chr);

    int r = get_entry(linky, "f");

    print_string("\n no errors");
}




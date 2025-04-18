#include "../../stdlib/kernel_headers.h"

void p_v() {

    print_string("_");

}

void print_inline(char* a){
    
    int size = str_size(a);

    for (int i = 0; i < size; i++) {print_char(a[i]);}

    
    const int blank = SCREEN_LINE_SIZE - size;
    

    for (int j = 0; j < blank; j++) {

        p_v();
    
    }

    

}

void print_parag(char* a) {

    struct ll* split = split_string(a, '\n');
   

}
#include "kernel_headers.h"


/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */

char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
  
    // Reverse the string
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}


void cpy(int* base, int* copied, int size) {

    for (int i = 0; i < size; i++) {

        base[i] = copied[i];

    };

}

int str_size(char* str) {

    int buffer = 0;

    while(1) {

        if (str[buffer] == 0x0) {return buffer;}

        buffer++;

    }

}


struct ll* new_ll(int size) {

    struct ll* buffer = (struct ll*) alloc(sizeof(struct ll) + size);

    buffer -> element_size = size; 

    buffer->next = 0;
    buffer->prev = 0;

    return buffer;

}

void set_element_val(struct ll* carrier, int* element) {

    cpy((int*)((char*)carrier + sizeof(struct ll)), element, carrier->element_size);


}; 

void push(struct ll* carrier, int* element) {

    

    struct ll* carrier_buffer = carrier;

    while((carrier_buffer -> next) != 0) {
        
        carrier_buffer = carrier_buffer -> next;
        
    }

    

    struct ll* buffer = (struct ll*) alloc(sizeof(struct ll) + (carrier_buffer -> element_size));

    buffer -> element_size = carrier_buffer -> element_size;

    buffer -> prev = carrier_buffer;

    buffer -> next = 0;

    carrier_buffer -> next = buffer;
    
    set_element_val(buffer, element);
    
    
}

int* get_element_val(struct ll* node) {
    return (int*)((char*)node + sizeof(struct ll));
}

void free_ll(struct ll* carrier) {
    struct ll* next;

    while (carrier != 0) {

        next = carrier->next;  

        free((int) carrier);         

        carrier = next;        
    }
}

int* get_nth_element(struct ll* carrier, int index) {

    struct ll* carrier_buffer = carrier;

    for (int i = 0; i < index ; i++) {

        if (carrier_buffer->next == 0) {

            print_string("OUT OF BOUNDS YOU DUMB FUCK");
            return 0; // or some error signal
        }

        carrier_buffer = carrier_buffer -> next;

    }

    

    return get_element_val(carrier_buffer);

}

void for_each(struct ll* carrier, void (*f)(void*)) {
    struct ll* current = carrier;

    while (current != 0) {
        f(get_element_val(current));
        current = current->next;
    }
}

void print_ll(struct ll* carrier) {

    struct ll* carrier_buffer = carrier;

    while ((carrier_buffer) != 0) {

        print_string((char*) get_element_val(carrier_buffer));

        carrier_buffer = carrier_buffer -> next;

    } ;

}

int get_str_ll_size(struct ll* carrier) {

    int buffer = 0;

    struct ll* carrier_buffer = carrier;

    while ((carrier_buffer) != 0) {

        buffer += str_size((char*) get_element_val(carrier_buffer)) ;

        carrier_buffer = carrier_buffer -> next;

    } ;

    return buffer;

}

enum bool string_eq(char* x, char* y){

    int length = min(str_size(x), str_size(y));

    for (int i = 0; i < length; i++) {

        if (x[i] != y[i]) {return  false;}

    }

    return true;

}

int max(int a, int b) {

    return (a > b) ? a : b;
    
}

int min(int a, int b) {

    return (a < b) ? a : b;
    
}

struct ll* as_string(char* chr) {
    int chr_index = 0;

    struct ll* linky = new_ll(sizeof(int*));

    char* first_char = (char*) alloc(sizeof(char));
    *first_char = chr[chr_index];
    set_element_val(linky, (int*) first_char);

    while (chr[chr_index] != 0x0) {
        chr_index++;

        char* next_char = (char*) alloc(sizeof(char));
        *next_char = chr[chr_index];
        push(linky, (int*) next_char);
    }

    return linky;
}

struct ll* split_string(char* strin, char element) {

    struct ll* linked_buffer = new_ll(sizeof(char*));

    int size = str_size(strin) + 1;

    char* sub_unit = (char*) alloc(sizeof(char) * 64);
    
    int sub_index = 0;

    enum bool first_flag = true;

    for (int i = 0; i < size; i++) {

        if (strin[i] == element || sub_index >= 63 || i == (size - 1)) {
            
            sub_unit[sub_index] = '\0'; 
            
            

            if (first_flag) {

                set_element_val(linked_buffer, (int*) sub_unit);

                first_flag = false;

            } else {    
                
                push(linked_buffer, (int*) sub_unit);
                
                

            }

                 

            sub_index = 0;

            sub_unit = (char*) alloc(sizeof(char) * 64);

            continue;
        }
        
        sub_unit[sub_index] = strin[i];

        sub_index++;

    }  

    return linked_buffer;

}
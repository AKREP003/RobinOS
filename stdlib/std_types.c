#include "kernel_headers.h"

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */

char* itoa(short value, char* result, short base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    short tmp_value;

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

short atoi(const char* str) {
    short result = 0;
    short sign = 1;

    
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }

    
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

void cpy(uintptr_t  base, uintptr_t  copied, short size) {

    for (short i = 0; i < size; i++) {

        *((char*) base + i) = *((char*) copied + i);

    };

}

short str_size(char* str) {

    short buffer = 0;

    while(1) {

        if (str[buffer] == 0x0) {return buffer;}

        buffer++;

    }

}


struct ll* new_ll() {

    struct ll* buffer = (struct ll*)  alloc(sizeof(struct ll));

    buffer->next = 0;
    buffer->prev = 0;
    buffer->val  = 0;

    return buffer;

}

void set_element_val(struct ll* carrier, uintptr_t element) {

    carrier -> val = element;


}; 

void push(struct ll* carrier, uintptr_t element) {

    

    struct ll* carrier_buffer = carrier;

    while((carrier_buffer -> next) != 0) {
        
        carrier_buffer = (struct ll*) carrier_buffer -> next;
        
    }

    uintptr_t buffer = alloc(sizeof(struct ll));

    ((struct ll*) buffer) -> prev = PTR carrier_buffer;

    ((struct ll*) buffer) -> next = PTR 0;

    carrier_buffer -> next = buffer;
    
    set_element_val(((struct ll*) buffer), element);
    
    
}

void push_dyn(struct ll* carrier, uintptr_t element) {



    if (carrier -> val == 0) {

        set_element_val(carrier, element);

    } else {

        push(carrier, element);

    }

}

uintptr_t get_element_val(struct ll* node) {
    return node -> val;
}

void free_ll(uintptr_t carrier) {
    uintptr_t next = PTR 0;

    while (carrier != 0) {

        next = ((struct ll*) carrier)->next;  

        free((LL carrier) ->val);

        free( carrier);

        carrier = next;        
    }


}

uintptr_t get_nth_element(struct ll* carrier, short index) {

    struct ll* carrier_buffer = carrier;

    for (short i = 0; i < index ; i++) {

        if (carrier_buffer->next == 0) {

            print_string("OUT OF BOUNDS YOU DUMB FUCK");
            return 0; // or some error signal
        }

        carrier_buffer = (struct ll*) carrier_buffer -> next;

    }

    

    return get_element_val(carrier_buffer);

}

void for_each(struct ll* carrier, void (*f)(uintptr_t)) {
    struct ll* current = carrier;

    while (current != 0) {
        f(get_element_val(current));
        current = (struct ll*) current->next;
    }
}

void print_ll(struct ll* carrier) {

    struct ll* carrier_buffer = carrier;

    while ((carrier_buffer) != 0) {

        print_string((char*) get_element_val(carrier_buffer));

        carrier_buffer = (struct ll*) carrier_buffer -> next;

    } ;

}

short get_ll_size(struct ll* carrier) {

    short buffer = 0;

    struct ll* carrier_buffer = carrier;

    while ((carrier_buffer) != 0) {

        buffer += 1;

        carrier_buffer = (struct ll*) carrier_buffer -> next;

    } ;

    return buffer;

}

enum bool string_eq(char* x, char* y){

    short length = min(str_size(x), str_size(y));

    for (short i = 0; i <= length; i++) {

        if (x[i] != y[i]) {return  false;}

    }

    return true;

}

short max(short a, short b) {

    return (a > b) ? a : b;
    
}

short min(short a, short b) {

    return (a < b) ? a : b;
    
}



struct ll* split_string(char* strin, char element) {
    
    struct ll* linked_buffer = new_ll();

    short size = str_size(strin) + 1;

    uintptr_t sub_unit = (uintptr_t) alloc(sizeof(char) * 64);
    
    short sub_index = 0;

    enum bool first_flag = true;

    for (short i = 0; i < size; i++) {

        if (strin[i] == element || sub_index >= 63 || i == (size - 1)) {
            
            ((char*) sub_unit)[sub_index] = '\0'; 

            if (str_size((char*) sub_unit) > 0) {

                if (first_flag) {
                    set_element_val(linked_buffer, sub_unit);
                    first_flag = false;
                } else {    
                    push(linked_buffer, (uintptr_t) sub_unit);
                }

            } else {
                // Free the unused sub_unit if it is empty
                free(sub_unit);
            }

            sub_index = 0;

            sub_unit = (uintptr_t) alloc(sizeof(char) * 64);

            continue;
        }
        
        ((char*) sub_unit)[sub_index] = strin[i];
        sub_index++;
    }

    // Free the last allocated sub_unit if it was not pushed
    if (sub_index == 0 || str_size((char*) sub_unit) == 0) {
        free(sub_unit);
    }

    return linked_buffer;
}

void print_integer(short number) {

    char* res = (char*) alloc(20);

    print_inline(itoa(number, res, 10));

    free((uintptr_t) res);

}

enum bool std_test() {

    enum bool str_eq_test =  string_eq("www", "www") && !(string_eq("www", "eee"));

    char* str = "aaaaa:bbbbb:cccc";

    
    struct ll* split = split_string(str, ':');

    enum bool split_test1 = string_eq(STR get_nth_element(split, 0), "aaaaa");

    enum bool split_test2 = string_eq(STR get_nth_element(split, 1), "bbbbb");

    return str_eq_test && split_test1 && split_test2;

}

uintptr_t allocate_str(char* str) {

    uintptr_t buffer = alloc(str_size(str) + 1);
    
    cpy(buffer, (uintptr_t) str, str_size(str) + 1);

    return PTR buffer;

}
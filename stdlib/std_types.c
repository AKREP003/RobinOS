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
            return 0; // or some error signal
        }

        carrier_buffer = carrier_buffer -> next;

    }

    

    return get_element_val(carrier_buffer);

}

void for_each(struct ll* carrier, int f) { //later

    

}

void print_ll(struct ll* carrier) {

    struct ll* carrier_buffer = carrier;

    while ((carrier_buffer) != 0) {

        print_string((char*) get_element_val(carrier_buffer));

        carrier_buffer = carrier_buffer -> next;

    } ;

}

int max(int a, int b) {

    return (a > b) ? a : b;
    
}

int min(int a, int b) {

    return (a < b) ? a : b;
    
}
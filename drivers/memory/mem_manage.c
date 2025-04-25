#include "../../stdlib/kernel_headers.h"


struct memblock {

    short size;
    
    uintptr_t prev;

    uintptr_t next;

};

typedef struct memblock* p_memblock;



uintptr_t last_free = (uintptr_t) 30000;

void set_heap_mode(short mode) {

    if (mode) {

        last_free = (uintptr_t) 30000;

    } else {

        last_free = (uintptr_t) 30000;

    }

}



uintptr_t alloc(short size) {

    uintptr_t buffer = (uintptr_t) 30000;

    //print_string("alloc called\r\n");

    uintptr_t alloc_size = size + sizeof(struct memblock);

    while (1) {
        
        if (((p_memblock) buffer)->next ==  (uintptr_t) 0) {

            uintptr_t alloc_addr = (uintptr_t) (buffer - alloc_size);

            ((p_memblock) buffer) -> next = alloc_addr;
            
            ((p_memblock) alloc_addr) -> size = size;
            
            ((p_memblock) alloc_addr) -> prev = (uintptr_t) buffer;

            ((p_memblock) alloc_addr) -> next = (uintptr_t) 0;


            return alloc_addr + sizeof(struct memblock);

        }

        short next_end = ((uintptr_t) ((p_memblock) buffer)->next) + (((p_memblock) ((p_memblock) buffer) -> next) -> size);

        
        if ( (buffer - next_end ) >= alloc_size && buffer != 30000) {
            


            uintptr_t alloc_addr = (uintptr_t) (buffer - alloc_size);
            
            ((p_memblock) alloc_addr) -> size = size;
            
            ((p_memblock) alloc_addr) -> prev = (uintptr_t) buffer;

            ((p_memblock) alloc_addr) -> next = (uintptr_t) ((p_memblock) buffer)->next;

            ((p_memblock) buffer) -> next = alloc_addr;
            

            return alloc_addr + sizeof(struct memblock);
            
            

        }

        

        buffer = ((p_memblock) buffer) -> next;

        
        
    };

    
    
    return 0;
}


void free(uintptr_t ptr) {
    
    if (ptr == 30000) {return;}

    

    p_memblock to_be_freed =  (p_memblock) (ptr - sizeof(struct memblock));

    p_memblock next = (p_memblock) to_be_freed -> next;

    p_memblock prev = (p_memblock) to_be_freed -> prev;

    if (next != 0) {next -> prev = (uintptr_t) prev;}

    if (prev != 0) {prev -> next = (uintptr_t) next;}

}

void dump_allocations() {
    
}

enum bool alloc_test() {

    char* test_str = "aaaaaaaaa";

    char* str = (char*) alloc(str_size(test_str) + 1);

    cpy((uintptr_t) str, (uintptr_t) test_str, str_size(test_str) + 1);

    enum bool test1 = string_eq(test_str, str);

    char* test_str2 = "aaaaaaaab";

    char* str2 = (char*) alloc(str_size(test_str2) + 1);

    cpy((uintptr_t) str2, (uintptr_t) test_str2, str_size(test_str2) + 1);


    enum bool test2 = string_eq(str2, test_str2);

    enum bool test3 = !string_eq(str2, str);

    free((uintptr_t) str);

    free((uintptr_t) str2);

    uintptr_t buffer = alloc(25);
    
    free(buffer);

    uintptr_t buffer2 = alloc(25);

    enum bool test4 = buffer == buffer2;

    free(buffer2);

    return test1 && test2 && test3 && test4;
}

#include "../../stdlib/kernel_headers.h"


struct memblock {

    short size;

    uintptr_t addr;
    
    struct memblock *prev;

    struct memblock *next;

};

typedef struct memblock* p_memblock;


struct memblock protected_head_allocation = {0, 30000, (p_memblock) 0, (p_memblock) 0};

struct memblock unprotected_head_allocation = {0, 0x100, (p_memblock) 0, (p_memblock) 0};

struct memblock* last_free = &protected_head_allocation;

void set_heap_mode(short mode) {

    if (mode) {

        last_free = &protected_head_allocation;

    } else {

        last_free = &unprotected_head_allocation;

    }

}



short get_end(p_memblock block) {
    return block->addr + block->size + sizeof(struct memblock);
}



uintptr_t alloc(short size) {

    p_memblock buffer = last_free;



    short alloc_size = size + sizeof(struct memblock);

    while (1) {
        
        if (buffer->next == 0) {

            p_memblock alloc_addr = (p_memblock) (buffer->addr - alloc_size);

            buffer -> next = alloc_addr;
            
            alloc_addr -> size = size;

            alloc_addr -> addr = (uintptr_t) alloc_addr;
            
            alloc_addr -> prev = buffer;

            alloc_addr -> next = 0;
            
            return (uintptr_t)((char*)alloc_addr + sizeof(struct memblock));

        }
        
        if (false) { //( (buffer->addr - get_end(buffer->next)) >= alloc_size ) {

            p_memblock alloc_addr = (p_memblock) (buffer->addr - alloc_size);
            
            alloc_addr -> next = buffer->next;

            buffer -> next = alloc_addr;
            
            alloc_addr -> size = size;

            alloc_addr -> addr = (uintptr_t) alloc_addr;
            
            alloc_addr -> prev = buffer;

            return (uintptr_t)((char*)alloc_addr + sizeof(struct memblock));


        }

        

        buffer = buffer -> next;

        
    };

    
    return 0;
}


void free(uintptr_t ptr) {
    // Step back from the allocated memory to find the memblock header
    p_memblock block = (p_memblock)(ptr - sizeof(struct memblock));

    // Reconnect the previous and next blocks to bypass 'block'
    if (block->prev != 0) {
        block->prev->next = block->next;
    }

    if (block->next != 0) {
        block->next->prev = block->prev;
    }

    // If the block was the last_free one, update last_free pointer
    if (last_free == block) {
        last_free = block->prev; // or set to head_allocation if you want a safe fallback
    }

    // Optional: zero out the block metadata (not required, but nice for debugging)
    block->size = 0;
    block->addr = 0;
    block->prev = 0;
    block->next = 0;
}

void dump_allocations() {
    p_memblock b = &protected_head_allocation;
    while (b != 0) {
        
        b = b->next;
    }
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

    return test1 && test2 && test3;
}


#define ENDPOINT 0x100000


struct memblock {

    int size;

    int addr;
    
    struct memblock *prev;

    struct memblock *next;

};

typedef struct memblock* p_memblock;


struct memblock head_allocation = {0, ENDPOINT, (p_memblock) 0, (p_memblock) 0};

struct memblock* last_free = &head_allocation;

int get_end(p_memblock block) {
    return block->addr + block->size + sizeof(struct memblock);
}



int alloc(int size) {

    p_memblock buffer = last_free;

    int alloc_size = size + sizeof(struct memblock);

    while (1) {
        
        if (buffer->next == 0) {

            p_memblock alloc_addr = (p_memblock) (buffer->addr - alloc_size);

            buffer -> next = alloc_addr;
            
            alloc_addr -> size = size;

            alloc_addr -> addr = (int) alloc_addr;
            
            alloc_addr -> prev = buffer;

            alloc_addr -> next = 0;

            return (int)((char*)alloc_addr + sizeof(struct memblock));

        }
        
        if ( (buffer->addr - get_end(buffer->next)) >= alloc_size ) {

            p_memblock alloc_addr = (p_memblock) (buffer->addr - alloc_size);
            
            alloc_addr -> next = buffer->next;

            buffer -> next = alloc_addr;
            
            alloc_addr -> size = size;

            alloc_addr -> addr = (int) alloc_addr;
            
            alloc_addr -> prev = buffer;

            return (int)((char*)alloc_addr + sizeof(struct memblock));


        }

        
    };

    
    return 0;
}


void free(int ptr) {
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
    p_memblock b = &head_allocation;
    while (b != 0) {
        
        b = b->next;
    }
}
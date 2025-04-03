
#define ENDPOINT 0x3000


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

            p_memblock alloc_addr = buffer->addr - alloc_size;

            buffer -> next = alloc_addr;
            
            alloc_addr -> size = size;

            alloc_addr -> addr = (int) alloc_addr;
            
            alloc_addr -> prev = buffer;

            alloc_addr -> next = 0;

            return alloc_addr + sizeof(struct memblock);
        }
        
        if ( (get_end(buffer->next) - buffer->addr) >= alloc_size ) {

            break;

        }

        
    };

    
    return 0;
}

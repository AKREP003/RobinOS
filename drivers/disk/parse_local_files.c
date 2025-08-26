
#include "../../stdlib/kernel_headers.h"

short DISK_HEADER = 0;

void discover_files() {
    
    char* disk_read_buffer = STR alloc(BLOCK_SIZE * 5);

    read_kernel((uintptr_t) disk_read_buffer);

    for (int i = 0; i < BLOCK_SIZE * 5; i++) {

        if (disk_read_buffer[i] == 'Q' && disk_read_buffer[i + 1] == 'Q' && disk_read_buffer[i + 2] == 'Q' && disk_read_buffer[i + 3] == 'Q') {

            

            DISK_HEADER = (short)i + 5;
            
            

            break;

        }

    }


    parse_files(&disk_read_buffer[DISK_HEADER]);

}

void parse_files(char* raw) {

    print_inline(raw);



    free(PTR raw);

}

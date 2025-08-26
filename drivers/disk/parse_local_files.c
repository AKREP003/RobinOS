
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

    short size = str_size(&disk_read_buffer[DISK_HEADER]) + 1;

    char* sized_buffer = (char*) alloc(size);

    for (int i = 0; i < size; i++) {

        sized_buffer[i] = (&(disk_read_buffer[DISK_HEADER]))[i];

    }

    
    free(PTR disk_read_buffer);

    parse_files(sized_buffer);

}

void parse_files(char* raw) {

    struct ll* sp = split_string(raw, '|');

    print_inline(get_nth_element(sp, 1));

    print_inline(raw);
    
    free(PTR raw);

}

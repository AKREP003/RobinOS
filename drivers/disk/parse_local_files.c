
#include "../../stdlib/kernel_headers.h"

short DISK_HEADER = 0;

void discover_files() {
    
    char* disk_read_buffer = STR alloc(BLOCK_SIZE * 10);

    read_kernel((uintptr_t) disk_read_buffer);

    for (int i = 0; i < BLOCK_SIZE * 10; i++) {

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

    print_integer(alloc(1));
    free(PTR disk_read_buffer);
    print_integer(alloc(1));

    print_inline("Discovered files: ");

    parse_files(sized_buffer);

}

void parse_files(char* raw) {

    print_integer(alloc(1));

    struct ll* sp = split_string(raw, '|');

    struct ll* sp_meta = split_string(get_nth_element(sp, 0), '+');

    char* raw_content = get_nth_element(sp, 1);

    print_integer(alloc(1));

    while (sp_meta != 0 && sp_meta->val != 0) {

        struct ll* file_data = split_string(sp_meta -> val, '=');

        short start = (short) atoi(get_nth_element(file_data, 1));

        short end;

        if ((sp_meta -> next) != 0 && ((LL (sp_meta -> next)) ->val != 0)){

            struct ll* next_file_data = split_string((LL (sp_meta -> next)) ->val, '=');

            end = (short) atoi(get_nth_element(next_file_data, 1));
            
            free_ll(PTR next_file_data);

        } else {

            end = str_size(raw_content);

        }

        char* name = get_nth_element(file_data, 0);

        char* file_content = get_slice(raw_content, start, end);

        print_inline(name);

        print_inline(file_content);

        register_file(name, file_content);

        sp_meta = (struct ll*) sp_meta->next;

        free_ll(PTR file_data);

    }

    free_ll(PTR sp_meta);
    
    free(PTR raw);

    print_integer(alloc(1));
}


void register_file(char* name, char* content) {

    print_integer(alloc(1));

    char* name_buffer = STR alloc(str_size(name) + 2);

    name_buffer[0] = ':';

    cpy((uintptr_t) (&name_buffer[1]), (uintptr_t) name, str_size(name) + 1);

    //struct file_cache* test = create_file_cache(name_buffer);

}

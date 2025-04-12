
#include "../../stdlib/kernel_headers.h"

#define FILE_SYTEM_HEADER 15
#define BLOCK_SIZE 512

enum file_type {

    exec,
    text,
    lib,
    fold

};

struct file_header {
    char name[64];

    enum file_type type;

    int block_count;

    struct disk_block* head_block;


};

struct disk_block {

    struct disk_block* prev;

    struct disk_block* next;
};

struct executable {

    char* name;

};

struct folder {

    char* name;

    struct file_header* file_array;

};

void write_file_header(int disk_ptr, char* file_name, enum file_type typ) {


    struct file_header* buffer = (struct file_header*) alloc(sizeof(struct file_header));


    cpy((int*) buffer->name, (int*) file_name, str_size(file_name));

    buffer -> type = typ;

    disk_write(sizeof(struct file_header), disk_ptr, (int) buffer);

    struct file_header* disk_read_buffer = (struct file_header*) alloc(sizeof(struct file_header)); //debug

    disk_read(sizeof(struct file_header), disk_ptr, (int) disk_read_buffer);

    print_string(disk_read_buffer -> name);
}

int parse_location(char* query) {

    return FILE_SYTEM_HEADER;

}

void create_file(char* location, char* name) {

    int disk_loc = parse_location(location);

    write_file_header(disk_loc, name, text);

}

void file_system_init() {

    write_file_header(FILE_SYTEM_HEADER, "base", fold);

}
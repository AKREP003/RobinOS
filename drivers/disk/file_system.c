
#include "../../stdlib/kernel_headers.h"

#define FILE_SYTEM_HEADER 15
#define BLOCK_SIZE 512

int free_slot = FILE_SYTEM_HEADER; // handle gaps in le future

struct file_header {
    char name[64];

    int block_count;

    int head_block;


};

struct disk_block {

    int cursor;

    int next;
};


void write_disk_block(int disk_loc) {

    struct disk_block* block = (struct disk_block*) alloc(BLOCK_SIZE);

    block -> next = 0;

    block -> cursor = sizeof(struct disk_block);

    disk_write(1, disk_loc, (int) block);

    free_slot++;



}

void write_file_header( char* file_name) {


    struct file_header* buffer = (struct file_header*) alloc(BLOCK_SIZE);

    cpy((int*) buffer->name, (int*) file_name, str_size(file_name));

    buffer -> head_block = free_slot + 1;
    

    disk_write(1, free_slot, (int) buffer);

    free_slot++;
    
    write_disk_block(free_slot);


    

}



void create_file(char* name) {

    
    write_file_header(name);


}

void file_system_init() {

    write_file_header("base");

}

void write_to_file(int file_loc, int* data, int size) {

    struct file_header* disk_read_buffer = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(sizeof(struct file_header), file_loc, (int) disk_read_buffer);

    
    struct disk_block* block_buffer = (struct disk_block*) alloc(BLOCK_SIZE);

    disk_read(1, disk_read_buffer -> head_block, (int) block_buffer);

    cpy((int*)((char*)block_buffer + block_buffer->cursor), data, size);


    block_buffer -> cursor += size;

    disk_write(1, disk_read_buffer -> head_block, (int) block_buffer);



    struct disk_block* block_buffer2 = (struct disk_block*) alloc(BLOCK_SIZE);


    disk_read(1, disk_read_buffer -> head_block, (int) block_buffer2);

    char* res = (char*) alloc(20);

    print_string((char*) ((int) block_buffer2 + 8));

}

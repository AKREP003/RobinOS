
#include "../../stdlib/kernel_headers.h"


int free_slot = FILE_SYTEM_HEADER; // handle gaps in le future



struct disk_block {

    int cursor;

    int next;
};


void write_disk_block(int disk_loc) {

    struct disk_block* block = (struct disk_block*) alloc(BLOCK_SIZE);

    block -> next = 0;

    block -> cursor = 0;

    disk_write(1, disk_loc, (int) block);

    



}

int write_file_header( char* file_name) {


    struct file_header* buffer = (struct file_header*) alloc(BLOCK_SIZE);

    cpy((int*) buffer->name, (int*) file_name, str_size(file_name));

    buffer -> head_block = free_slot + 1;

    int slot_buffer = free_slot;

    disk_write(1, free_slot, (int) buffer);

    struct file_header* buffer2 = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(1, free_slot, (int) buffer2);

    print_string(buffer2 -> name);

    free_slot++;
    
    write_disk_block(free_slot);

    free_slot++;

    
    return slot_buffer;

}






void write_to_file(int file_loc, int* data, int size) {

    int original_size = size;
    
    struct file_header* disk_read_buffer = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(sizeof(struct file_header), file_loc, (int) disk_read_buffer);

    struct disk_block* block_buffer = (struct disk_block*) alloc(BLOCK_SIZE);

    disk_read(1, disk_read_buffer -> head_block, (int) block_buffer);

    
    int block_ptr = disk_read_buffer -> head_block;

    while (true) {

        int to_be_written = min(size, BLOCK_SIZE - (block_buffer -> cursor) - sizeof(struct disk_block));

        cpy((int*)((char*)block_buffer + block_buffer->cursor + sizeof(struct disk_block)), data, to_be_written);

        size -= to_be_written;
        
        block_buffer -> cursor += to_be_written;

        disk_write(1, block_ptr, (int) block_buffer);

        if (size <= 0) {break;}

        if (block_buffer -> next == 0) {

            write_disk_block(free_slot);

            block_buffer -> next = free_slot;

            free_slot++;

            disk_read(1, block_buffer -> next, (int) block_buffer);

        } else {

            disk_read(1, block_buffer -> next, (int) block_buffer);

        }

        block_ptr = block_buffer -> next;

    }

    disk_read_buffer -> size += original_size;

    disk_write(1, file_loc, (int) disk_read_buffer);

    free((int) disk_read_buffer);

    free((int) block_buffer);

}


int* read_file(int file_loc) {

    struct file_header* disk_read_buffer = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(1, file_loc, (int) disk_read_buffer);

    int size_buffer = disk_read_buffer -> size;

    int* data_buffer = (int*) alloc(disk_read_buffer -> size);

    struct disk_block* block_buffer = (struct disk_block*) alloc(BLOCK_SIZE);

    disk_read(1, disk_read_buffer -> head_block, (int) block_buffer);

    while(1) {

        int block_to_read = min(BLOCK_SIZE, block_buffer -> cursor + sizeof(struct disk_block));

        cpy(data_buffer + (disk_read_buffer -> size - size_buffer) , (int*) ((char*) block_buffer + sizeof(struct disk_block)), block_to_read - sizeof(struct disk_block));

        size_buffer -= block_to_read;

        if (size_buffer <= 0 || block_buffer -> next == 0) {break;}

        disk_read(1, block_buffer -> next, (int) block_buffer);


    };

    free((int) block_buffer);

    return data_buffer;

}

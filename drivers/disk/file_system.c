
// FIT IMPLEMENTATOIN //

#include "../../stdlib/kernel_headers.h"


short free_slot = FILE_SYTEM_HEADER; // handle gaps in le future

short DISK_HEADER = 0;

struct disk_block {

    short cursor;

    short next;
};


void write_disk_block(short disk_loc) {

    struct disk_block* block = (struct disk_block*) alloc(BLOCK_SIZE);

    block -> next = 0;

    block -> cursor = 0;

    disk_write(1, disk_loc, (uintptr_t) block);

    free((uintptr_t) block);    



}

short write_file_header( char* file_name) {


    struct file_header* buffer = (struct file_header*) alloc(BLOCK_SIZE);

    cpy((uintptr_t) buffer->name, (uintptr_t) file_name, str_size(file_name));

    buffer -> head_block = free_slot + 1;

    short slot_buffer = free_slot;

    disk_write(1, free_slot, (uintptr_t) buffer);

    free_slot++;
    
    write_disk_block(free_slot);

    free_slot++;

    free((uintptr_t) buffer);

    
    return slot_buffer;

}


struct file_header* read_file_header(short loc) {

    struct file_header* disk_read_buffer = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(sizeof(struct file_header), loc, (uintptr_t) disk_read_buffer);

    return disk_read_buffer;

}

struct disk_block* read_block(short loc) {

    struct disk_block* block_buffer = (struct disk_block*) alloc(BLOCK_SIZE);

    disk_read(1, loc, (uintptr_t) block_buffer);

    return block_buffer;

}



void write_to_file_pointer(short file_loc, uintptr_t data, short size) {

    short original_size = size;
    
    struct file_header* disk_read_buffer = read_file_header(file_loc);

    struct disk_block* block_buffer = read_block(disk_read_buffer -> head_block);

    short block_ptr = disk_read_buffer -> head_block;

    while (true) {

        short to_be_written = min(size, BLOCK_SIZE - (block_buffer -> cursor) - sizeof(struct disk_block));

        cpy((uintptr_t)((char*)block_buffer + block_buffer->cursor + sizeof(struct disk_block)), data, to_be_written);

        size -= to_be_written;
        
        block_buffer -> cursor += to_be_written;

        disk_write(1, block_ptr, (uintptr_t) block_buffer);

        if (size <= 0) {break;}

        if (block_buffer -> next == 0) {

            write_disk_block(free_slot);

            block_buffer -> next = free_slot;

            free_slot++;

            disk_read(1, block_buffer -> next, (uintptr_t) block_buffer);

        } else {

            disk_read(1, block_buffer -> next, (uintptr_t) block_buffer);

        }

        block_ptr = block_buffer -> next;

    }

    disk_read_buffer -> size += original_size;

    disk_write(1, file_loc, (uintptr_t) disk_read_buffer);

    free((uintptr_t) disk_read_buffer);

    free((uintptr_t) block_buffer);

    
}

void write_to_file(short file_loc, uintptr_t data, short size) {
    
    struct file_header* disk_read_buffer = read_file_header(file_loc);

    struct disk_block* block_buffer = read_block(disk_read_buffer -> head_block);

    short block_ptr = disk_read_buffer -> head_block;

    while (true) {

        short to_be_written = min(size, BLOCK_SIZE - sizeof(struct disk_block));

        cpy((uintptr_t)((char*)block_buffer + sizeof(struct disk_block)), data, to_be_written);

        size -= to_be_written;
        
        block_buffer -> cursor = to_be_written;

        disk_write(1, block_ptr, (uintptr_t) block_buffer);

        if (size <= 0) {break;}

        if (block_buffer -> next == 0) {

            write_disk_block(free_slot);

            block_buffer -> next = free_slot;

            free_slot++;

            disk_read(1, block_buffer -> next, (uintptr_t) block_buffer);

        } else {

            disk_read(1, block_buffer -> next, (uintptr_t) block_buffer);

        }

        block_ptr = block_buffer -> next;

    }

    disk_read_buffer -> size = size;

    disk_write(1, file_loc, (uintptr_t) disk_read_buffer);

    free((uintptr_t) disk_read_buffer);

    free((uintptr_t) block_buffer);

}

uintptr_t read_file(short file_loc) {

    struct file_header* disk_read_buffer = (struct file_header*) alloc(BLOCK_SIZE);

    disk_read(1, file_loc, (uintptr_t) disk_read_buffer);

    short size_buffer = disk_read_buffer -> size;

    uintptr_t data_buffer = (uintptr_t) alloc(disk_read_buffer -> size + 5);

    

    struct disk_block* block_buffer = (struct disk_block*) alloc(BLOCK_SIZE);

    disk_read(1, disk_read_buffer -> head_block, (uintptr_t) block_buffer);


    while(1) {

        short block_to_read = min(BLOCK_SIZE, block_buffer -> cursor + sizeof(struct disk_block));

        cpy((uintptr_t) (data_buffer + (disk_read_buffer -> size - size_buffer)) , (uintptr_t) ((char*) block_buffer + sizeof(struct disk_block)), block_to_read - sizeof(struct disk_block));

        size_buffer -= block_to_read;

        if (size_buffer <= 0 || block_buffer -> next == 0) {break;}

        disk_read(1, block_buffer -> next, (uintptr_t) block_buffer);


    };



    (STR disk_read_buffer)[disk_read_buffer -> size] = (char) 0;

    free((uintptr_t) block_buffer);

    free((uintptr_t) disk_read_buffer);

    

    return data_buffer;

}

void discover_files() {
    

    char* disk_read_buffer = STR alloc(BLOCK_SIZE * 15);

    read_kernel((uintptr_t) disk_read_buffer);

    for (int i = 0; i < BLOCK_SIZE * 15; i++) {

        if (disk_read_buffer[i] == 'q' && disk_read_buffer[i + 1] == 'q' && disk_read_buffer[i + 2] == 'q') {

            

            DISK_HEADER = (short)i + 3;
            
            

            break;

        }

    }


    free((uintptr_t) disk_read_buffer);

}

enum bool file_system_test() {
    
    short loc = write_file_header("test");

    char* str1 = "aws";

    write_to_file(loc, (uintptr_t) str1, 4);

    char* buffer = (char*) read_file(loc);
    
    

    enum bool test1 = string_eq(buffer, str1);

    short loc2 = write_file_header("test2");

    char* str2 = "aqs";

    write_to_file(loc2, (uintptr_t) str2, 4);
    
    char* buffer2 = (char*) read_file(loc2);

    enum bool test2 = string_eq(buffer2, str2);

    enum bool test3 = !string_eq(buffer2, buffer);

    free((uintptr_t) buffer);

    free((uintptr_t) buffer2);

    

    return test1 && test2 && test3;
}

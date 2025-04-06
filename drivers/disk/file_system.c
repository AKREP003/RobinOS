

#define FILE_SYTEM_HEADER = 0x2000
#define BLOCK_SIZE = 512

enum file_type {

    exec,
    text,
    lib,
    fold

};

struct file_header {
    char* name;

    enum file_type type;

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
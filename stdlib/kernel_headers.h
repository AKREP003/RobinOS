void print_string(char *str);

void read(int sector_numb, int cylinder, int sector, int head, int buffer);
void long_disk_read(int size, int disk_addr, int mem_addr);
void write(int sector_numb, int cylinder, int sector, int head, int buffer);

void free(int ptr);
void disk_read(int size, int disk_addr, int mem_addr);
int alloc(int size);
void disk_write(int size, int disk_addr, int mem_addr);
void set_heap_mode(int mode);
void cpy(int* base, int* copied, int size);
char* itoa(int value, char* result, int base);
int str_size(char* str);
void create_file(char* location, char* name);
void file_system_init();
struct ll* new_ll(int size);
void set_element_val(struct ll* carrier, int* element);
void push(struct ll* carrier, int* element);
int* get_element_val(struct ll* node);
void free_ll(struct ll* carrier);
int* get_nth_element(struct ll* carrier, int index);
void print_ll(struct ll* carrier);

struct ll {

    int element_size;

    struct ll * next;

    struct ll * prev;



};

enum bool {
    true = 1,
    fale = 0
};


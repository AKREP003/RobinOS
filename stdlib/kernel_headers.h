#define FILE_SYTEM_HEADER 50
#define BLOCK_SIZE 512

#define SCREEN_LINE_SIZE 77


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
void create_file(char* name, char* location);
void file_system_init();
struct ll* new_ll(int size);
void set_element_val(struct ll* carrier, int* element);
void push(struct ll* carrier, int* element);
int* get_element_val(struct ll* node);
void free_ll(struct ll* carrier);
int* get_nth_element(struct ll* carrier, int index);
void print_ll(struct ll* carrier);
void write_to_file(int file_loc, int* data, int size);
int max(int a, int b);
int min(int a, int b);
int* read_file(int file_loc);
struct ll* as_string(char* chr);
struct ll* split_string(char* strin, char element);
struct ll* parse_folder(char* data);
int get_str_ll_size(struct ll* carrier);
int get_entry(struct ll* fold, char* key);
enum bool string_eq(char* x, char* y);
int atoi(const char* str);
int write_file_header( char* file_name);
void print_integer(int number);
void test_em_all();
void print_char(char c);
void for_each(struct ll* carrier, void (*f)(void*));
void print_inline(char* a);
void get_current_time();
void wait_sec(int seconds);

enum bool disk_test();
enum bool alloc_test();
enum bool std_test();

struct ll {

    int element_size;

    struct ll * next;

    struct ll * prev;



};

enum bool {
    true = 1,
    false = 0
};

struct file_header {
    char name[64];

    int size;

    int head_block;


};

extern unsigned int HOUR;
extern unsigned int MIN;
extern unsigned int SEC;
#include <stdint.h>


#define FILE_SYTEM_HEADER 50
#define BLOCK_SIZE 512

#define SCREEN_LINE_SIZE 77


void print_string(char *str);
void read(short sector_numb, short cylinder, short sector, short head, uintptr_t buffer);
void long_disk_read(short size, short disk_addr, short mem_addr);
void write(short sector_numb, short cylinder, short sector, short head, uintptr_t buffer);
void free(uintptr_t ptr);
void disk_read(short size, short disk_addr, uintptr_t mem_addr);
uintptr_t alloc(short size);
void disk_write(short size, short disk_addr, uintptr_t mem_addr);
void set_heap_mode(short mode);
void cpy(uintptr_t  base, uintptr_t  copied, short size);
char* itoa(short value, char* result, short base);
short str_size(char* str);
struct file_cache* create_file_cache(char* location);
void file_system_init();
struct ll* new_ll();
void set_element_val(struct ll* carrier, uintptr_t element);
void push(struct ll* carrier, uintptr_t element);
uintptr_t get_element_val(struct ll* node);
void free_ll(uintptr_t carrier);
uintptr_t get_nth_element(struct ll* carrier, short index);
void print_ll(struct ll* carrier);
void write_to_file_pointer(short file_loc, uintptr_t data, short size);
short max(short a, short b);
short min(short a, short b);
uintptr_t read_file(short file_loc);
struct ll* split_string(char* strin, char element);
struct ll* parse_folder(char* data);
short get_ll_size(struct ll* carrier);
short get_entry(struct ll* fold, char* key);
enum bool string_eq(char* x, char* y);
short atoi(const char* str);
short write_file_header( char* file_name);
void print_integer(short number);
void test_em_all();
void print_char(char c);
void for_each(struct ll* carrier, void (*f)(uintptr_t));
void print_inline(char* a);
void get_current_time();
void wait_sec( short seconds);
short get_nth_fibo(short n);
void wake_up();
uintptr_t allocate_str(char* str);
void write_to_file(short file_loc, uintptr_t data, short size);
struct file_header* read_file_header(short loc);
void commit_file_cache(struct file_cache* dat);
void refresh_file_cache(struct file_cache* dat);
void write_to_cache(char* text, struct file_cache* cache);
void start_video_mode();
void read_key();
void wait_tick( short ticks);
void console_init();
short parse_file_path(char* path);
struct ll* parse_folder(char* data);
void dump_allocations();
struct file_cache* create_file_cache_from(char* location);

enum bool file_system_test();
enum bool disk_test();
enum bool alloc_test();
enum bool std_test();
enum bool file_handling_test();

struct ll {

    uintptr_t val;

    uintptr_t next;

    uintptr_t prev;



};

enum bool {
    true = 1,
    false = 0
};

struct file_header {
    char name[64];

    short size;

    short head_block;


};

struct file_cache {

    char* name;
 
    short disc_loc;
 
    short parent_loc;
 
    uintptr_t buffer;
 
    char* tree_loc;
 
    short size;
 
    enum bool lock;
 
 };
 

extern  short HOUR;
extern  short MIN;
extern  short SEC;
extern  short TICKS_HIGH;
extern  short TICKS_LOW;


extern  char KEY_READ;

#define PTR (uintptr_t)
#define STR (char*)
#define LL (struct ll*)
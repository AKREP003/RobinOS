void print_string(char *str);
void disk_read(int size, int disk_addr, int mem_addr);
int alloc(int size);
void disk_write(int size, int disk_addr, int mem_addr);
void set_heap_mode(int mode);
void cpy(int* base, int* copied, int size);
char* itoa(int value, char* result, int base);
int str_size(char* str);
void create_file(char* query);
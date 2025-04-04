void print_string(char *str);
void disk_read(int size, int disk_addr, int mem_addr);
int alloc(int size);


void aaa() {
    print_string("well come to HatcimOS!\n");
    print_string("booting...");

    int buffer = alloc(512);

    disk_read(1, 0, buffer);

    print_string((char*) buffer); 

    
}


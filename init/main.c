void print_string(char *str);
void disk_read(int size, int disk_addr, int mem_addr);
int alloc(int size);
void disk_write(int size, int disk_addr, int mem_addr);




void aaa() {
    print_string("well come to RobinOS!\n");
    
    

    char* stir = "aaa";
    
    print_string((char*) stir); 

    disk_write(512, 0x0, (int) stir);

    

    char* buffer = (char*) 0x7000;

    disk_read(512, 0x0, (int) buffer);

    print_string((char*) buffer); 

    
}


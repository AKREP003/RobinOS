void print_string(char *str);
void disk_read(int size, int disk_addr, int mem_addr);
int alloc(int size);
void disk_write(int size, int disk_addr, int mem_addr);




void aaa() {
    print_string("well come to RobinOS!\n");
    
    

    char* buffer = (char*) 0x8000;

    buffer[0] = 'A';
    buffer[1] = 'A';
    buffer[2] = 'A';
    

    print_string(buffer); 

    //disk_write(512, 30000, (int) buffer);

    print_string((char*) buffer); 

    //disk_read(512, 30000, buffer);

    print_string((char*) buffer); 

    
}


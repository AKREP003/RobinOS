void print_string(char *str);
void disk_read(int size, int disk_addr, int mem_addr);

char buffer[512] = {0};;

void aaa() {
    print_string("hello world\n");
    
    //disk_read(0, 1000, (int) &buffer);

    print_string("aaaaaaa");

    print_string(buffer);

    print_string("aaaaaaa");
}


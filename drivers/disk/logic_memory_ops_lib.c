
#define HEADS 255
#define SECTORS 63
#define SECTOR_SIZE 512

void read(int sector_numb, int cylinder, int sector, int head, int buffer);

void write(int sector_numb, int cylinder, int sector, int head, int buffer);

void print_string(char *str);

void disk_read(int size, int disk_addr, int mem_addr) {

    int sector = (disk_addr % SECTORS) + 1;
    int head = (disk_addr / SECTORS) % HEADS;
    int cylinder = (disk_addr / (SECTORS * HEADS)) % 1024; 

    int sectors_to_read = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;;

    

    read(sectors_to_read, cylinder, sector, head, mem_addr);
    
}

void disk_write(int size, int disk_addr, int mem_addr) {

    int sector = (disk_addr % SECTORS) + 1;
    int head = (disk_addr / SECTORS) % HEADS;
    int cylinder = (disk_addr / (SECTORS * HEADS)) % 1024; 

    int sectors_to_read = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;

    write(sectors_to_read, cylinder, sector, head, mem_addr);
    
}



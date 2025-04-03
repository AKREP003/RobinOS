
#define HEADS 255
#define SECTORS 63
#define SECTOR_SIZE 512

void read(int sector_numb, int cylinder, int sector, int head, int buffer);

int ceil(float a) {
    int b = (int)a;
    if (a - b > 0) {
        return b + 1;
    }
    return b;
}

void disk_read(int size, int disk_addr, int mem_addr) {

    int sector = (disk_addr % SECTORS) + 1;
    int head = (disk_addr / SECTORS) % HEADS;
    int cylinder = (disk_addr / (SECTORS * HEADS)) % 1024; // Assuming 1024 cylinders

    int sectors_to_read = ceil((float)size / SECTOR_SIZE);

    read(sectors_to_read, cylinder, sector, head, mem_addr);
}




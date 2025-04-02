void print_string(char *str);

char* sppp = "bbbbbbbaaaaaaaaaaaaaaaaa";

void calculate_disk_parameters(unsigned long memory_size_bytes) {
    const unsigned int SECTOR_SIZE = 512; // BIOS sector size in bytes
    const unsigned int HEADS = 2;         // Number of heads (default for floppy disks)
    const unsigned int SECTORS_PER_TRACK = 18; // Number of sectors per track (default for floppy disks)

    // Calculate total sectors
    unsigned long total_sectors = memory_size_bytes / SECTOR_SIZE;

    // Calculate cylinders
    unsigned long cylinders = total_sectors / (HEADS * SECTORS_PER_TRACK);

    
}

void aaa() {
    print_string("god ");
    print_string("is ");
    print_string("dead");
    
    
}

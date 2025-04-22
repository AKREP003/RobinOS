
#include "../../stdlib/kernel_headers.h"

void read_long(short ds_buff, short si_buff);

#define HEADS 255
#define SECTORS 63
#define SECTOR_SIZE 512


short* shc_adressing(short disk_addr, short size) {

    short* buffer = (short*) alloc(40);

    buffer[0] = max(1, (disk_addr % SECTORS)); 
    buffer[1] = ((disk_addr / SECTORS) % HEADS) + 1;
    buffer[2] = (disk_addr / (SECTORS * HEADS)) % 1024; 
    buffer[3] = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;

    return buffer;
}

void disk_read(short size, short disk_addr, uintptr_t mem_addr) {

    short* buffer = shc_adressing(disk_addr, size);

    read(buffer[3], buffer[0], buffer[1], buffer[2], mem_addr);

    
    
}

void long_disk_read(short size, short disk_addr, short mem_addr) {
    // Allocate 16-byte Disk Address Packet (DAP)
    unsigned char* dap = (unsigned char*) alloc(16);

    short sector_count = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;

    // Fill the Disk Address Packet
    dap[0] = 0x10; // Size of DAP
    dap[1] = 0x00; // Reserved

    // Sector count (2 bytes)
    dap[2] = sector_count & 0xFF;
    dap[3] = (sector_count >> 8) & 0xFF;

    
    dap[4] = mem_addr & 0xFF;
    dap[5] = (mem_addr >> 8) & 0xFF;
    dap[6] = (mem_addr >> 16) & 0xFF;
    dap[7] = (mem_addr >> 24) & 0xFF;

    
    dap[8]  = disk_addr & 0xFF;
    dap[9]  = (disk_addr >> 8) & 0xFF;
    dap[10] = (disk_addr >> 16) & 0xFF;
    dap[11] = (disk_addr >> 24) & 0xFF;
    dap[12] = 0x00; 
    dap[13] = 0x00;
    dap[14] = 0x00;
    dap[15] = 0x00;

    // Split dap pointer into segment:offset for real-mode BIOS
    unsigned short dap_addr = (unsigned int) dap;
    unsigned short dap_segment = dap_addr >> 4;
    unsigned short dap_offset  = dap_addr & 0xF;

    // Call BIOS interrupt 0x13 via read_long
    read_long(dap_segment, dap_offset);

    // Free the buffer
    free((int) dap);
}


void disk_write(short size, short disk_addr, uintptr_t mem_addr) {

    short* buffer = shc_adressing(disk_addr, size);

    write(buffer[3], buffer[0], buffer[1], buffer[2], mem_addr);

    print_char('Q');

    
    
}

enum bool disk_test() {

    char* test_str = "aws";

    short disk_addr = 100;

    print_inline("aaaa");
    

    disk_write(1, disk_addr, (uintptr_t) test_str);

    

    char* buffer = (char*) alloc(str_size(test_str) + 1);

    disk_read(1, disk_addr, (uintptr_t) buffer);

    enum bool test1 = string_eq(test_str, "buffer");
    return test1;

}

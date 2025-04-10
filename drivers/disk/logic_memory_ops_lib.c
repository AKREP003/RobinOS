
#include "../../stdlib/kernel_headers.h"

void read_long(int ds_buff, int si_buff);

#define HEADS 255
#define SECTORS 63
#define SECTOR_SIZE 512


int* shc_adressing(int disk_addr, int size) {

    int* buffer = (int*) alloc(40);

    buffer[0] = (disk_addr % SECTORS) + 1; 
    buffer[1] = ((disk_addr / SECTORS) % HEADS) + 1;
    buffer[2] = (disk_addr / (SECTORS * HEADS)) % 1024; 
    buffer[3] = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;

    return buffer;
}

void disk_read(int size, int disk_addr, int mem_addr) {

    int* buffer = shc_adressing(disk_addr, size);

    read(buffer[3], buffer[0], buffer[1], buffer[2], mem_addr);

    free((int) buffer);
    
}

void long_disk_read(int size, int disk_addr, int mem_addr) {
    // Allocate 16-byte Disk Address Packet (DAP)
    unsigned char* dap = (unsigned char*) alloc(16);

    int sector_count = (size + SECTOR_SIZE - 1) / SECTOR_SIZE;

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
    unsigned int dap_addr = (unsigned int) dap;
    unsigned short dap_segment = dap_addr >> 4;
    unsigned short dap_offset  = dap_addr & 0xF;

    // Call BIOS interrupt 0x13 via read_long
    read_long(dap_segment, dap_offset);

    // Free the buffer
    free((int) dap);
}


void disk_write(int size, int disk_addr, int mem_addr) {

    int* buffer = shc_adressing(disk_addr, size);

    write(buffer[3], buffer[0], buffer[1], buffer[2], mem_addr);

    

    free((int) buffer);
    
}



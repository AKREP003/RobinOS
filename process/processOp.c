
#include "../stdlib/std_types.c"
#include <stdint.h>

enum bool;

struct Process {

    char* name;

    enum bool typ;

    int text_start;
    int text_size;

    int data_start;
    int data_size;

};



struct GDTEntry {
    uint16_t limit_low;     // Lower 16 bits of limit
    uint16_t base_low;      // Lower 16 bits of base
    uint8_t  base_middle;   // Next 8 bits of base
    uint8_t  access;        // Access flags
    uint8_t  granularity;   // Flags and high 4 bits of limit
    uint8_t  base_high;     // Last 8 bits of base
} __attribute__((packed));


void fill_gdt_entry(struct GDTEntry* entry, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
    entry->limit_low = limit & 0xFFFF;
    entry->base_low = base & 0xFFFF;
    entry->base_middle = (base >> 16) & 0xFF;
    entry->access = access;
    entry->granularity = ((limit >> 16) & 0x0F) | (flags & 0xF0);
    entry->base_high = (base >> 24) & 0xFF;
}



void create_gdt_for_process(struct Process* proc, struct GDTEntry* gdt) {
    
    // Code segment
    fill_gdt_entry(&gdt[0], proc->text_start, proc->text_size - 1, 0x9A, 0xC0); // execute/read

    // Data segment
    fill_gdt_entry(&gdt[1], proc->data_start, proc->data_size - 1, 0x92, 0xC0); // read/write
}

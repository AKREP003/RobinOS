CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld



bios_memory_ops.o disk.o : bios_memory_ops.asm logic_memory_ops_lib.c
	$(AS) $(ASFLAGS) bios_memory_ops.asm -o bios_memory_ops.o 

	$(CC) $(CFLAGS) logic_memory_ops_lib.c -o disk.o -lm



clean:
	rm -f *.o *.bin $(TARGET)
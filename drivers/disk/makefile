CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld



bios_memory_ops.o disk.o file_system.o file_handling.o parse_local_files.o: bios_memory_ops.asm logic_memory_ops_lib.c file_system.c file_handling.c parse_local_files.c
	$(AS) $(ASFLAGS) bios_memory_ops.asm -o bios_memory_ops.o 

	$(CC) $(CFLAGS) -fno-stack-protector logic_memory_ops_lib.c -o disk.o -lm

	$(CC) $(CFLAGS) -fno-stack-protector file_system.c -o file_system.o

	$(CC) $(CFLAGS) -fno-stack-protector file_handling.c -o file_handling.o

	$(CC) $(CFLAGS) -fno-stack-protector parse_local_files.c -o parse_local_files.o


clean:
	rm -f *.o *.bin $(TARGET)
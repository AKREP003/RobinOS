CC=gcc
AS=nasm
LD=ld
CFLAGS=-ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld



std_types.o : std_types.c
	$(CC) $(CFLAGS) std_types.c -o std_types.o


clean:
	rm -f *.o *.bin $(TARGET)
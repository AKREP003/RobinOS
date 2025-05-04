CC=gcc
AS=nasm
LD=ld
CFLAGS=-ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld

process.o : process.c
	
	$(CC) $(CFLAGS) -fno-stack-protector process.c -o process.o



clean:
	rm -f *.o *.bin $(TARGET)
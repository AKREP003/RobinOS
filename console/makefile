
CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

console.o : console.c

	$(CC) $(CFLAGS) -fno-stack-protector console.c -o console.o


clean:
	rm -f *.o *.bin
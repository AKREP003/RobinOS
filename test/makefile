CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

test.o : tests.c

	$(CC) $(CFLAGS) -fno-stack-protector tests.c -o test.o

clean:
	rm -f *.o *.bin
CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld

mem_manage.o: mem_manage.c 
	$(CC) $(CFLAGS) -fno-stack-protector -c mem_manage.c -o mem_manage.o

clean:
	rm -f *.o *.bin 
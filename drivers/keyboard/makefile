CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld

keyboard_ops.o : Ckeyboard_driver.c
	
	$(CC) $(CFLAGS)   -c Ckeyboard_driver.c -o keyboard_ops.o

clean:
	rm -f *.o *.bin $(TARGET)
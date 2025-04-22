CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp


timer_logic.o timer.o : timer_logic.c timer.asm
	$(AS) $(ASFLAGS) timer.asm -o timer.o 

	$(CC) $(CFLAGS) timer_logic.c -o timer_logic.o -lm

clean:
	rm -f *.o *.bin 
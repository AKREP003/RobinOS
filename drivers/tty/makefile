
CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

tty_driver.o tty_logic.o: tty_driver.asm tty_logic.c
	$(AS) $(ASFLAGS) tty_driver.asm -o tty_driver.o

	$(CC) $(CFLAGS) -fno-stack-protector tty_logic.c -o tty_logic.o


clean:
	rm -f *.o *.bin $(TARGET)
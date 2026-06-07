
CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

#tty_driver.asm tty_driver.o
#$(AS) $(ASFLAGS) tty_driver.asm -o tty_driver.o

tty_logic.o tty_driver.o:  tty_logic.c Ctty_driver.c
	
	

	$(CC) $(CFLAGS)  tty_logic.c -o tty_logic.o

	$(CC) $(CFLAGS)  Ctty_driver.c -o tty_driver.o


clean:
	rm -f *.o *.bin $(TARGET)
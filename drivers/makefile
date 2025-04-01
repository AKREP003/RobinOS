CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld

tty_driver.o: tty_driver.asm
	$(AS) $(ASFLAGS) tty_driver.asm -o tty_driver.o

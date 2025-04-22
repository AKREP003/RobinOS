CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

boot.bin: boot.asm
	$(AS) -f bin boot.asm -o boot.bin


clean:
	rm -f *.o *.bin $(TARGET)

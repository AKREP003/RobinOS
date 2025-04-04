CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld

mode_ops.o : mode_ops.asm
	$(AS) $(ASFLAGS) mode_ops.asm -o mode_ops.o 

clean:
	rm -f *.o *.bin $(TARGET)
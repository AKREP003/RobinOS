CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
LDFLAGS=-m elf_i386 -T linker.ld

vda_text_ops.o : vda_text_ops.asm
	$(AS) $(ASFLAGS) vda_text_ops.asm -o vda_text_ops.o 

clean:
	rm -f *.o *.bin $(TARGET)
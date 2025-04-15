CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld
TARGET=os.flp

all: $(TARGET)

$(TARGET): boot/boot.bin init/kernel.bin files/files.bin

	cat boot/boot.bin init/kernel.bin > $(TARGET)
	
	truncate -s 1024M $(TARGET)

	$(MAKE) clean -C boot 

	$(MAKE) clean -C init 

	$(MAKE) clean -C files

	$(MAKE) clean -C test


boot/boot.bin : 
	$(MAKE) -C boot CC=gcc AS=nasm LD=ld CFLAGS="-m32 -ffreestanding -nostdlib -m16 -c -fno-pic" ASFLAGS="-f elf32" LDFLAGS="-m elf_i386 -T linker.ld"

init/kernel.bin :
	$(MAKE) -C init CC=gcc AS=nasm LD=ld CFLAGS="-m32 -ffreestanding -nostdlib -m16 -c -fno-pic" ASFLAGS="-f elf32" LDFLAGS="-m elf_i386 -T linker.ld" 

files/files.bin: 

	$(MAKE) -C files

clean:
	rm -f *.o *.bin $(TARGET)

	$(MAKE) clean -C boot 

	$(MAKE) clean -C init 

	$(MAKE) clean -C files

	$(MAKE) clean -C test
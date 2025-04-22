CC=gcc
AS=nasm
LD=ld
CFLAGS= -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf
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
	$(MAKE) -C boot 

init/kernel.bin :
	$(MAKE) -C init

files/files.bin: 

	$(MAKE) -C files

clean:
	rm -f *.o *.bin $(TARGET)

	$(MAKE) clean -C boot 

	$(MAKE) clean -C init 

	$(MAKE) clean -C files

	$(MAKE) clean -C test
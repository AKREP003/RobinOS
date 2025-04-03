CC=gcc
AS=nasm
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -m16 -c -fno-pic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386 -T linker.ld



disk/disk.o disk/logic_memory_ops_lib.o tty/tty_driver.o memory/mem_manage.o:
	$(MAKE) -C disk

	$(MAKE) -C tty

	$(MAKE) -C memory

clean:
	rm -f *.o *.bin $(TARGET)

	$(MAKE) -C tty clean
	$(MAKE) -C disk clean
	$(MAKE) -C memory clean

drivers = ../drivers/tty/tty_driver.o ../drivers/disk/bios_memory_ops.o ../drivers/disk/disk.o ../drivers/disk/file_system.o ../drivers/disk/file_handling.o ../drivers/memory/mem_manage.o  
stdlib = ../stdlib/std_types.o
test = ../test/test.o


kernel.bin: kernel.o $(stdlib) $(drivers) $(test) main.o
	
	$(LD) $(LDFLAGS) kernel.o $(stdlib) $(drivers) $(test) main.o -o kernel.bin

main.o: main.c
	$(CC) $(CFLAGS) -fno-stack-protector main.c -o main.o

kernel.o: kernel.asm
	$(AS) $(ASFLAGS) kernel.asm -o kernel.o


$(stdlib) :
	$(MAKE) -C ../stdlib

$(drivers) :
	$(MAKE) -C ../drivers

$(test) :

	$(MAKE) -C ../test

clean:
	rm -f *.o *.bin $(TARGET)
	
	$(MAKE) -C ../drivers clean
	$(MAKE) -C ../stdlib clean
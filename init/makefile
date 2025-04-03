
drivers = ../drivers/tty/tty_driver.o ../drivers/disk/bios_memory_ops.o ../drivers/disk/disk.o 


kernel.bin: kernel.o $(drivers) main.o
	
	$(LD) $(LDFLAGS) kernel.o $(drivers) main.o -o kernel.bin

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

kernel.o: kernel.asm
	$(AS) $(ASFLAGS) kernel.asm -o kernel.o

$(drivers) :
	$(MAKE) -C ../drivers

clean:
	rm -f *.o *.bin $(TARGET)
	
	$(MAKE) -C ../drivers clean


kernel.bin: kernel.o ../drivers/tty_driver.o main.o
	
	$(LD) $(LDFLAGS)  kernel.o ../drivers/tty_driver.o main.o -o kernel.bin

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

kernel.o: kernel.asm
	$(AS) $(ASFLAGS) kernel.asm -o kernel.o

../drivers/tty_driver.o:
	$(MAKE) -C ../drivers

clean:
	rm -f *.o *.bin $(TARGET)
	
	$(MAKE) -C ../drivers clean
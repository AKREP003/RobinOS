
tty_driver.o tty_logic.o: tty_driver.asm tty_logic.o
	$(AS) $(ASFLAGS) tty_driver.asm -o tty_driver.o

	$(CC) $(CFLAGS) -fno-stack-protector tty_logic.c -o tty_logic.o


clean:
	rm -f *.o *.bin $(TARGET)
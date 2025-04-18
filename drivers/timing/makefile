
timer_logic.o timer.o : timer_logic.c timer.asm
	$(AS) $(ASFLAGS) timer.asm -o timer.o 

	$(CC) $(CFLAGS) timer_logic.c -o timer_logic.o -lm

clean:
	rm -f *.o *.bin 
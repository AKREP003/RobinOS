

bios_memory_ops.o disk.o file_system.o file_handling.o: bios_memory_ops.asm logic_memory_ops_lib.c file_system.c file_handling.c
	$(AS) $(ASFLAGS) bios_memory_ops.asm -o bios_memory_ops.o 

	$(CC) $(CFLAGS) -fno-stack-protector logic_memory_ops_lib.c -o disk.o -lm

	$(CC) $(CFLAGS) -fno-stack-protector file_system.c -o file_system.o

	$(CC) $(CFLAGS) -fno-stack-protector file_handling.c -o file_handling.o


clean:
	rm -f *.o *.bin $(TARGET)
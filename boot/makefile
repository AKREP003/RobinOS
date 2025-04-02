
clean:
	rm -f *.o *.bin $(TARGET)

boot.bin: boot.asm
	$(AS) -f bin boot.asm -o boot.bin
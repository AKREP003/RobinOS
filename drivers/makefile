drivers = ../drivers/tty/tty_driver.o ../drivers/tty/tty_logic.o ../drivers/disk/bios_memory_ops.o ../drivers/disk/disk.o ../drivers/disk/file_system.o ../drivers/disk/file_handling.o ../drivers/memory/mem_manage.o ../drivers/timing/timer.o ../drivers/timing/timer_logic.o 



$(drivers):
	$(MAKE) -C disk

	$(MAKE) -C tty

	$(MAKE) -C memory

	$(MAKE) -C timing

clean:
	rm -f *.o *.bin $(TARGET)

	$(MAKE) -C tty clean
	$(MAKE) -C disk clean
	$(MAKE) -C memory clean
	$(MAKE) -C timing clean
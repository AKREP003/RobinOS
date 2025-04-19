
mk_drivers:
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
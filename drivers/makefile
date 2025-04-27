
mk_drivers:
	$(MAKE) -C disk

	$(MAKE) -C tty

	$(MAKE) -C memory

	$(MAKE) -C timing

	$(MAKE) -C VDA_text

	$(MAKE) -C keyboard

clean:
	rm -f *.o *.bin $(TARGET)

	$(MAKE) -C tty clean
	$(MAKE) -C disk clean
	$(MAKE) -C memory clean
	$(MAKE) -C timing clean
	$(MAKE) -C VDA_text clean
	$(MAKE) -C keyboard clean
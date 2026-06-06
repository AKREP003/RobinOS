integration_test.o : integration_test
	rustc +nightly  --crate-type staticlib integration_test/src/lib.rs --target integration_test/targets/i686-unknown-none.json --emit obj -o integration_test.o 

	


clean :
	#rm integration_test.o
set pagination off
set confirm off

add-symbol-file init/kernel.elf 0x1000

source -s -v memLeakCheck

target remote localhost:1234

c
set pagination off
set confirm off
add-symbol-file init/kernel.elf 0x1000
target remote localhost:1234
c
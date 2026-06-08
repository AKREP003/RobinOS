wsl --exec make -C /mnt/c/users/aliek/desktop/projeler/c/simpleos

start cmd /k wsl --exec qemu-system-x86_64 -s -S -fda os.flp -m 4096 -nographic

wsl --cd /mnt/c/users/aliek/desktop/projeler/c/simpleos  --exec gdb


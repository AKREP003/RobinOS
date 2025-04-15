[BITS 16]
[ORG 0x7C00]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sti

    ; Load kernel at 0x1000
    mov ah, 0x02
    mov al, 45
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, 0
    mov bx, 0x1000
    int 0x13
    jc disk_error

    jmp 0x1000

disk_error:
    hlt

    ; Boot signature
    times 510-($-$$) db 0
    dw 0xAA55

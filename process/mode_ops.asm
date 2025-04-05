gdt_start: ;https://wiki.osdev.org/Global_Descriptor_Table
    dq 0                   ; Null descriptor

    ; Code segment: base=0, limit=4GB, flags=0x9A
    dw 0xFFFF              ; limit low
    dw 0x0000              ; base low
    db 0x00                ; base middle
    db 10011010b           ; access byte
    db 11001111b           ; flags + limit high
    db 0x00                ; base high

    ; Data segment: base=0, limit=4GB, flags=0x92
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00

gdt_end:

gdt_descriptor:
    dw 15  ; Size of GDT
    dd gdt_start                ; Address of GDT

load_gdt:
    lgdt [gdt_descriptor]

    cli

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp 0x08:protected_mode_entry   ; 0x08 = offset of code segment in GDT

    protected_mode_entry:
    mov ax, 0x10      ; 0x10 = data segment offset in GDT
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Now you're in protected mode!

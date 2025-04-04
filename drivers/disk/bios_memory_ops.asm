[BITS 16]
global read
global write

read:
    push ebp
    mov ebp, esp

    mov ah, 0x02        ; BIOS function 0x02 - Read sectors
    mov al, [ebp + 8]   ; Number of sectors to read
    mov ch, [ebp + 12]  ; Cylinder number (0-79)
    mov cl, [ebp + 16]  ; Sector number (1-18)
    mov dh, [ebp + 20]  ; Head number (0-1)
    mov dl, 0        ; Floppy Drive 0 (A:)
    mov bx, [ebp + 24]  ; Buffer address in memory

    int 0x13            ; BIOS Disk Read
    jc disk_error       ; Jump to error if Carry Flag is set

    mov esp, ebp 
    pop ebp          ; Restore stack frame
    retn 20             ; Clean up (5 parameters × 4 bytes)

write:

    push ebp
    mov ebp, esp

    mov ah, 0x03        ; BIOS function 0x02 - write sectors
    mov al, [ebp + 8]   ; Number of sectors to read
    mov ch, [ebp + 12]  ; Cylinder number (0-79)
    mov cl, [ebp + 16]  ; Sector number (1-18)
    mov dh, [ebp + 20]  ; Head number (0-1)
    mov dl, 0x0           ; Drive number (0x80 for first hard drive, 0 for floppy)  
    mov bx, [ebp + 24]  ; Buffer address in memory

    int 0x13            ; BIOS Disk Read
    jc disk_error       ; Jump to error if Carry Flag is set

    mov esp, ebp 
    pop ebp          ; Restore stack frame
    retn 20             ; Clean up (5 parameters × 4 bytes)



disk_error:
    hlt                 ; Halt on error


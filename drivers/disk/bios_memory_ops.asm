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


; LBA Read Function
read_long:
    push ebp
    mov ebp, esp

    ; Set up for LBA mode (Function 0x42 - Read sectors using LBA)
    mov ah, 0x42         ; BIOS function 0x42 - Read sectors using LBA
    mov al, [ebp + 8]    ; Number of sectors to read (AL)
    mov bx, [ebp + 24]   ; Buffer address in memory (BX)

    ; LBA Addressing (32-bit LBA)
    mov eax, [ebp + 12]  ; LBA start address (low 16 bits)
    mov dx, [ebp + 16]   ; LBA start address (high 16 bits)

    ; Set up disk parameters (drive 0 for floppy, or specify other drives)
    mov dl, 0            ; Floppy Drive 0 (A:), set DL to 0 for default drive

    ; Call BIOS interrupt for reading
    int 0x13             ; BIOS Disk Read (LBA Mode)
    jc disk_error        ; Jump to error handling if Carry Flag is set

    ; Clean up and return from function
    mov esp, ebp
    pop ebp               ; Restore stack frame
    retn 20               ; Clean up the stack (5 parameters × 4 bytes)

; LBA Write Function
write_long:
    push ebp
    mov ebp, esp

    ; Set up for LBA mode (Function 0x43 - Write sectors using LBA)
    mov ah, 0x43         ; BIOS function 0x43 - Write sectors using LBA
    mov al, [ebp + 8]    ; Number of sectors to write (AL)
    mov bx, [ebp + 24]   ; Buffer address in memory (BX)

    ; LBA Addressing (32-bit LBA)
    mov eax, [ebp + 12]  ; LBA start address (low 16 bits)
    mov dx, [ebp + 16]   ; LBA start address (high 16 bits)

    ; Set up disk parameters (drive 0 for floppy, or specify other drives)
    mov dl, 0            ; Floppy Drive 0 (A:), set DL to 0 for default drive

    ; Call BIOS interrupt for writing
    int 0x13             ; BIOS Disk Write (LBA Mode)
    jc disk_error        ; Jump to error handling if Carry Flag is set

    ; Clean up and return from function
    mov esp, ebp
    pop ebp               ; Restore stack frame
    retn 20               ; Clean up the stack (5 parameters × 4 bytes)

disk_error:
    hlt                  ; Halt on error (could be improved with a proper error message)


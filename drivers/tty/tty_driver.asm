[BITS 16]
global print_string
; https://medium.com/@nadavlevy1000/functions-in-assembly-the-stack-34f5c1917a81
print_string:
    push ebp
    mov ebp, esp
  
    sub esp, 4 
    mov si, [ebp + 8] 
    mov ah, 0Eh          ; BIOS teletype output function

.repeat:
    lodsb                ; Load byte at SI into AL and increment SI
    test al, al          ; Check if AL == 0 (end of string)
    jz .done             ; If it's 0 (null terminator), end of string
    int 10h              ; Print character in AL using BIOS interrupt
    jmp .repeat

.done:
    mov esp, ebp 
    pop ebp
    retn 4  

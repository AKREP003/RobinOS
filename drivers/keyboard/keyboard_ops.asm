[BITS 16]
global read_key
global KEY_READ

KEY_READ    db 0    

read_key:
    mov ah, 1
    int 16h           
    jz no_key         ;

    
    mov ah, 0
    int 16h          
    mov [KEY_READ], al
    ret

no_key:
    mov byte [KEY_READ], 0  ; No key pressed
    ret

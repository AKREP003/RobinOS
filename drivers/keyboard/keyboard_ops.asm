[BITS 16]
global read_key
global KEY_READ

KEY_READ    db 0    

read_key:
    mov ah, 0      
    int 16h        
    mov [KEY_READ], al  

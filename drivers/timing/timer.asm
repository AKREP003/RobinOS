[BITS 16]

global HOUR
global MIN
global SEC
global get_current_time

HOUR    db 0
MIN     db 0
SEC     db 0

get_current_time:
    mov ah, 0x02
    int 0x1A        

    mov [HOUR], ch
    mov [MIN], cl
    mov [SEC], dh

    ret

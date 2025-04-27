[BITS 16]

global HOUR
global MIN
global SEC
global get_current_time
global TICKS_HIGH
global TICKS_LOW



HOUR    db 0
MIN     db 0
SEC     db 0
TICKS_HIGH dw 0
TICKS_LOW  dw 0


get_current_time:
    mov ah, 0x02
    int 0x1A        

    mov [HOUR], ch
    mov [MIN], cl
    mov [SEC], dh

    mov [TICKS_HIGH], cx   
    mov [TICKS_LOW], dx    

    ret

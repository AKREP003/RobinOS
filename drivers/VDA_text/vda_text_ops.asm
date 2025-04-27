[BITS 16]
global start_video_mode

start_video_mode:

    mov ah, 0x00      
    mov al, 0x03      
    int 0x10
    ret


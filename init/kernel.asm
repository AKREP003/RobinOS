[BITS 16]

extern aaa
global _start

_start:
    

	call aaa	; Call our string-printing routine

	jmp $			; Jump here - infinite loop!


	text_string db 'hello world!', 0



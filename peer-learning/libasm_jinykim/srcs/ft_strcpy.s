; params
; rdi, rsi, rdx, r10, r8, r9
; char *  stpcpy(char * dst, const char * src);

section .text
	global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx 		; i = 0
	cmp rdi, 0			; if dst == 0 
	je return
	cmp rsi, 0			; if src == 0
	je return
	jmp loop

loop:
	xor rdx, rdx 
	cmp BYTE [rsi + rcx], 0				; *(src + i) == 0
	je return
	mov dl, BYTE [rsi + rcx]	
	mov BYTE [rdi + rcx], dl 	; *(dst+i) = *(src+i)
	inc rcx								; i++
	jmp loop

return:
	xor dl, dl 
	mov BYTE[rdi + rcx], dl
	mov rax, rdi
	ret

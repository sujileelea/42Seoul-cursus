; params
; rdi, rsi, rdx, r10, r8, r9

section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	cmp rdi, 0
	je return
	jmp loop

loop:
	cmp BYTE [rdi + rax], 0
	je return
	inc rax	
	jmp loop

return:
	ret

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy

; char *     strdup(const char *s1);
_ft_strdup:
	xor rax, rax
	cmp rdi, 0
	je _return
	push rdi		;; rdi 스택에 저장
	call _ft_strlen
	inc rax			;; ft_strlen의 반환값 + 1
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je _return
	pop rsi
	mov rdi, rax
	call _ft_strcpy ; rdi는 malloc한 포인터, rsi는 s1
	ret
	; 길이 구하고
	
_return:
	ret

; params
; rdi, rsi, rdx, r10, r8, r9
; int strcmp(const char *s1, const char *s2);
; int		ft_strcmp(char *s1, char *s2)
; {
; 	unsigned int i;
; 
; 	i = 0;
; 	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
; 		i++;
; 	return (unsigned int)s1[i] - (unsigned int)s2[i];
; }
section .text
	global _ft_strcmp

_ft_strcmp:
	xor rcx, rcx 		; i = 0
	xor rax, rax
	xor rdx, rdx
	cmp rdi, 0			; if dst == 0 
	je return
	cmp rsi, 0			; if src == 0
	je return 
	jmp loop

loop:
	cmp BYTE [rsi + rcx], 0				; src[i] == 0
	je return
	cmp BYTE [rdi + rcx], 0				; dst[i] == 0
	je return
	mov dl, BYTE [rdi + rcx]	
	cmp dl, BYTE [rsi + rcx]
	jne return 
	inc rcx
	jmp loop

return:
	xor rax, rax
	xor rdx, rdx 
	mov al, BYTE [rdi + rcx]
	mov dl, BYTE [rsi + rcx]
	sub eax, edx
	ret

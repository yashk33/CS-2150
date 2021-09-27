; Yash Kolli, 4/12/2021 mathlib.s

	global product
	global power

	section .text

product:
	xor  r11, r11
	xor  rax, rax

loop:
	cmp r11, rsi
	je  endproduct
	
	add rax, rdi
	inc r11
	
	jmp loop

endproduct:
	ret

power:
	cmp rsi, 0
	je  endpower
	xor rax, rax
	mov rax, 1

recursion:
	dec  rsi
	call power
	
	mov  rsi, rax
	call product

endpower:
	ret
	
	

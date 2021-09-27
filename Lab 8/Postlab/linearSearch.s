	;; linearSearch.s Yash Kolli, 4/15/21

	global linearSearch

	section .text

linearSearch:
	xor	r10, r10	;clear out required registers
	xor	r11, r11
	
	xor	rax, rax

search:	
	cmp	r11, rsi	;check to see if end has been reached
	je	notFound
	
	add	r10, [rdi + 4 * r11] ;store curr val in r10
	
	cmp	r10d, edx	;check to see if value has been found
	je	found
	
	inc	r11		;increase counter by 1
	xor	r10, r10
	
	jmp	search		;return to beginning

found:
	mov	rax, r11
	ret

notFound:
	mov	rax, -1
	ret

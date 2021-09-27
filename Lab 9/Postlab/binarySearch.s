	;;Yash Kolli, 4/22/21, binarySearch.s


	global binarySearch

	section .text

binarySearch:
	xor r10, r10	          	;clear out required registers
	xor r11, r11
	xor rax, rax

	cmp rsi, rdx			;determine where to jump

	jg  exit
	
	add r10, rdx			;setting target and comparing
	add r10, rsi
	shr r10, 1

	mov r11, [r10 * 4 + rdi]

	cmp ecx, r11d			;determine where to jump

	jl  lessThan
	je  equalTo
	jg  greaterThan

lessThan:
	mov rdx, r10			;search indexes below if less
	sub rdx, 1
	jmp binarySearch

equalTo:
	mov rax, r10			;return if found 
	ret

greaterThan:
	mov rsi, r10			;search indexes above if greater	 
	inc rsi
	jmp binarySearch

exit:
	mov rax, -1			;if not found, returns -1
	ret

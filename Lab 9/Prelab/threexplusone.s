	;;Yash Kolli, 4/19/21, threeexplusone.s


	global threexplusone

	section .text


threexplusone:
	xor r10, r10	          	;clear required registers
	xor rax, rax

begin:
	mov r10, rdi
	cmp rdi, 1    		        ;check to jump end
	je  finish

	and r10, 1		        ;check jump to evenstep 
	jz  evenstep

	lea rdi, [rdi + rdi + rdi + 1] 	;optimized method for implementing 3x + 1
	inc rax

evenstep:
	shr rdi, 1			;optimized method for dividing by 2	
	inc rax
	call begin

finish:
	ret

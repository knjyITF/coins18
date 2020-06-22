	.text
	.globl main
main:	mov $0,	%eax
	mov $0, %edx
L1:	cmp $11, %eax
	je L2
	add %eax, %edx
	add $1, %eax
	jmp L1
L2:	call finish

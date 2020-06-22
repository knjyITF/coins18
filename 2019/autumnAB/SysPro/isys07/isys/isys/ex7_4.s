.data
a:	.long 32, 78, 41, 20, 63, 98, 14, 5, 76, 88, 11, 49, 0
.text
.globl main
main:	mov $0, %ebx
	mov $0, %eax

L1:	cmp $0, a(,%ebx,4)
	je L2
	add a(,%ebx,4), %eax
	add $1, %ebx
	jmp L1

L2:	call finish

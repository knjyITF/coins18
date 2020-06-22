	.data
x:	.long 0x3456cdef # 2+1+2+2+2+3+3+4 = 19 = 0x13
	.text
	.global main
main:	mov $0, %eax
	mov x(,%eax,4), %ebx
.L1:	cmp $0, %ebx
	je .L3
	shl $1, %ebx
	JC .L2
	jmp .L1
.L2:	add $1, %eax
	jmp .L1
.L3:	call finish

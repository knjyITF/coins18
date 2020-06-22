	.data
x: 	.long 120, -100, 60, -200
y: 	.long 10, 50, -3, -25
z: 	.long 0, 0, 0, 0
	.text
        .global main
main:	mov $0, %ecx
.L1:	cmp $4, %ecx
	je .L2
	mov x(,%ecx,4), %eax
	mov y(,%ecx,4), %edx
	idiv %edx
	mov %eax, z(,%ecx,4)
	add $1, %ecx
	jmp .L1
.L2:	mov $0, %edi
	mov z(,%edi,4), %eax
	add $1, %edi
	mov z(,%edi,4), %ebx
        add $1, %edi
	mov z(,%edi,4), %ecx
        add $1, %edi
	mov z(,%edi,4), %edx
	call finish

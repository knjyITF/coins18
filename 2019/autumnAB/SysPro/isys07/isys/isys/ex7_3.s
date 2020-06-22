	.text
	.globl main
main:	mov $0, %eax #f(n)
	mov $0, %ebx #f(n-1)
	mov $0, %ecx #f(n-2)
	mov $0, %edx #n

L0:	cmp $21, %edx
	je L1

	cmp $0, %edx
	je L2

	cmp $1, %edx
	je L3

	mov $0, %edi
	add %ebx, %edi
	add %ecx, %edi
	mov %edi, %eax

	mov %ebx, %ecx
	mov %eax, %ebx

N:	add $1, %edx
	jmp L0


L2:	mov $0, %eax
	jmp N	
	
L3:	mov $1, %eax
	mov $1, %ebx
	jmp N


L1:	call finish

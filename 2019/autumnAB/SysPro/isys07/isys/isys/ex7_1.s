	.text
	.globl main
main:
	mov $1, %eax
	mov $2, %ebx
	mov $3, %ecx
	mov $4, %edx
	mov $0, %edi
	
	add %eax, %edi
	add %ebx, %edi
	add %ecx, %edi
	add %edx, %edi
	call finish

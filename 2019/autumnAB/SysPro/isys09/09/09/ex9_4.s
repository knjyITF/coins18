.text
.global make_allone_array
make_allone_array:
	push %ebp
	mov %esp, %ebp

	push 8(%ebp)
	call malloc
	mov 8(%ebp), %ecx
	mov $0, %edi
	mov $1, %edx

.L1:	cmp %ecx, %edi
	je .L2
	mov %edx, (%eax,%edi,4)
	inc %edi
	jmp .L1

.L2:	mov %ebp, %esp
	pop %ebp
	ret

.text
.global main
main:	push $20
	call fib
	call finish

fib:	push %ebp
	mov %esp, %ebp
	mov 8(%ebp), %edx
	cmp $1, %edx
	jle .L1

	dec %edx
	push %edx
	call fib
	pop %edx
	push %eax
	dec %edx
	push %edx
	call fib
	pop %ecx
	pop %ecx
	add %ecx, %eax
	jmp .L2

.L1:	mov %edx,%eax
.L2:	leave
	ret

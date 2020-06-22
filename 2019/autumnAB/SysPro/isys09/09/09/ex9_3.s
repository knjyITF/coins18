.text
.global sum
sum:    push %ebp
        mov %esp, %ebp
        mov 8(%ebp), %ecx
        mov $0, %eax
        mov 12(%ebp), %edx

.L1:    cmp $0, %ecx
        je .L2
	dec %ecx
        add (%edx,%ecx,4), %eax
        jmp .L1

.L2:    mov %ebp, %esp
        pop %ebp
        ret

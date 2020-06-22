.text
.global determinant
determinant:
        push %ebp
        mov %esp, %ebp
        mov 8(%ebp), %eax
        imul 20(%ebp), %eax
        mov 12(%ebp), %ecx
        imul 16(%ebp), %ecx
        sub %ecx, %eax
        mov %ebp, %esp
        pop %ebp
        ret

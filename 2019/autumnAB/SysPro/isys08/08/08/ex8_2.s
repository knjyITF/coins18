	.data
x: 	.long 0x754f5900, 0x758f6640, 0x6d20645c, 0x000a2167
y: 	.long 0xfedcba98, 0x76543210, 0x9abcdef0, 0x00045678
	.text
	.global main
main:	mov $0, %edi
	mov x(,%edi,4), %edx
	add y(,%edi,4), %edx
	add $1, %edi
	
	mov x(,%edi,4), %ecx
	adc y(,%edi,4), %ecx
	add $1, %edi

	mov x(,%edi,4), %ebx
        adc y(,%edi,4), %ebx
        add $1, %edi

	mov x(,%edi,4), %eax
        adc y(,%edi,4), %eax

	call finish

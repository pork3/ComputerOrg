	.file	"lab4.c"
	.text
	.globl	leftShift
	.type	leftShift, @function
leftShift:
.LFB23:
	.cfi_startproc
	movl	8(%esp), %ecx
	movl	4(%esp), %eax
	sall	%cl, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	leftShift, .-leftShift
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

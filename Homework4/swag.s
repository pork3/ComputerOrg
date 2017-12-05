	.file	"swag.c"
	.text
	.globl	loop
	.type	loop, @function
loop:
.LFB23:
	.cfi_startproc
.L2:
	jmp	.L2
	.cfi_endproc
.LFE23:
	.size	loop, .-loop
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
.L4:
	jmp	.L4
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

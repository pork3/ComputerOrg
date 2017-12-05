	.file	"test.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %eax        
	leal	(%eax,%eax,2), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.globl	g
	.type	g, @function
g:
.LFB1:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	leal	(%eax,%eax,2), %ecx
	leal	(%edx,%edx,2), %eax
	addl	%ecx, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	g, .-g
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

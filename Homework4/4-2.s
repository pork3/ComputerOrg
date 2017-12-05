	.file	"4-2.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%esi, %esi
	addl	$1, %esi
	subl	$4, %esp
	.cfi_def_cfa_offset 24
	movl	24(%esp), %ebx
	leal	52(%ebx), %ebp
	leal	4(%ebx), %edi
	addl	$56, %ebx
	cmpl	$13, %esi
	je	.L8
	.p2align 4,,10
	.p2align 3
.L4:
	movl	%edi, %edx
	movl	%ebp, %eax
	movl	%esi, (%esp)
	.p2align 4,,10
	.p2align 3
.L3:
	movl	(%edx), %esi
	movl	(%eax), %ecx
	addl	$4, %eax
	addl	$52, %edx
	movl	%esi, -4(%eax)
	movl	%ecx, -52(%edx)
	cmpl	%ebx, %eax
	jne	.L3
	movl	(%esp), %esi
	addl	$52, %ebp
	addl	$4, %edi
	addl	$56, %ebx
	addl	$1, %esi
	cmpl	$13, %esi
	jne	.L4
.L8:
	addl	$4, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE23:
	.size	transpose, .-transpose
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

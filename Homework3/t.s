	.file	"t.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	sortArray
	.type	sortArray, @function
sortArray:
.LFB0:
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
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	44(%esp), %eax
	movl	40(%esp), %ebp
	movl	$0, (%esp)
	subl	$1, %eax
	movl	%eax, 16(%esp)
	movl	16(%esp), %esi
	leal	4(%ebp), %eax
	cmpl	%esi, (%esp)
	movl	%eax, 4(%esp)
	jge	.L9
	.p2align 4,,10
	.p2align 3
.L5:
	movl	(%esp), %esi
	movl	%esi, %eax
	addl	$1, %eax
	cmpl	%eax, 44(%esp)
	movl	%eax, %ecx
	movl	%eax, 8(%esp)
	jle	.L3
	movl	4(%esp), %ebx
	movl	-4(%ebx), %eax
	movl	%eax, 12(%esp)
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%ebx), %edx
	leal	0(%ebp,%esi,4), %edi
	cmpl	%eax, %edx
	cmovl	%ecx, %esi
	cmovl	%ebx, %edi
	cmpl	%edx, %eax
	cmovg	%edx, %eax
	addl	$1, %ecx
	addl	$4, %ebx
	cmpl	%ecx, 44(%esp)
	jne	.L4
	cmpl	(%esp), %esi
	je	.L3
	movl	4(%esp), %esi
	movl	%eax, -4(%esi)
	movl	12(%esp), %eax
	movl	%eax, (%edi)
.L3:
	movl	8(%esp), %eax
	addl	$4, 4(%esp)
	movl	16(%esp), %esi
	movl	%eax, (%esp)
	cmpl	%esi, (%esp)
	jl	.L5
.L9:
	addl	$20, %esp
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
.LFE0:
	.size	sortArray, .-sortArray
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	swapl
	.type	swapl, @function
swapl:
.LFB1:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %eax
	movl	(%edx), %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	%ecx, (%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1:
	.size	swapl, .-swapl
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

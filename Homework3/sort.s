	.file	"sort.c"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC0:
	.string	"Enter some numbers to populate this array"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Enter a number: "
.LC2:
	.string	"%d"
	.text
	.globl	readArray
	.type	readArray, @function
readArray:
.LFB38:
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
	subl	$24, %esp
	.cfi_def_cfa_offset 44
	movl	44(%esp), %edi
	leal	0(,%edi,4), %eax
	pushl	%eax
	.cfi_def_cfa_offset 48
	call	malloc
	movl	%eax, %ebp
	movl	$.LC0, (%esp)
	call	puts
	addl	$16, %esp
	.cfi_def_cfa_offset 32
	testl	%edi, %edi
	jle	.L2
	movl	%ebp, %esi
	movl	$0, %ebx
.L3:
	subl	$12, %esp
	.cfi_def_cfa_offset 44
	pushl	$.LC1
	.cfi_def_cfa_offset 48
	call	puts
	addl	$8, %esp
	.cfi_def_cfa_offset 40
	pushl	%esi
	.cfi_def_cfa_offset 44
	pushl	$.LC2
	.cfi_def_cfa_offset 48
	call	__isoc99_scanf
	addl	$1, %ebx
	addl	$4, %esi
	addl	$16, %esp
	.cfi_def_cfa_offset 32
	cmpl	%ebx, %edi
	jne	.L3
.L2:
	movl	%ebp, %eax
	addl	$12, %esp
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
.LFE38:
	.size	readArray, .-readArray
	.globl	swap
	.type	swap, @function
swap:
.LFB39:
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
.LFE39:
	.size	swap, .-swap
	.globl	swapl
	.type	swapl, @function
swapl:
.LFB40:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %ecx
	movl	(%edx), %eax
	xorl	(%ecx), %eax
	movl	%eax, (%edx)
	xorl	(%ecx), %eax
	movl	%eax, (%ecx)
	xorl	%eax, (%edx)
	ret
	.cfi_endproc
.LFE40:
	.size	swapl, .-swapl
	.globl	sortArray
	.type	sortArray, @function
sortArray:
.LFB41:
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
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %ebx
	movl	32(%esp), %esi
	movl	%ebx, %ebp
	movl	$0, %ecx
	leal	-1(%esi), %eax
	movl	%eax, 4(%esp)
	jmp	.L10
.L14:
	leal	1(%ecx), %edi
	cmpl	%edi, %esi
	jle	.L11
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	%ecx, (%esp)
.L13:
	movl	(%ebx,%edx,4), %ecx
	cmpl	%ecx, (%ebx,%eax,4)
	cmovl	%eax, %edx
	addl	$1, %eax
	cmpl	%eax, %esi
	jne	.L13
	movl	(%esp), %ecx
	cmpl	%ecx, %edx
	je	.L11
	leal	(%ebx,%edx,4), %eax
	pushl	%eax
	.cfi_def_cfa_offset 32
	pushl	%ebp
	.cfi_def_cfa_offset 36
	call	swapl
	addl	$8, %esp
	.cfi_def_cfa_offset 28
.L11:
	addl	$4, %ebp
	movl	%edi, %ecx
.L10:
	cmpl	4(%esp), %ecx
	jl	.L14
	addl	$8, %esp
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
.LFE41:
	.size	sortArray, .-sortArray
	.section	.rodata.str1.1
.LC3:
	.string	"%d "
	.text
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB42:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %edi
	movl	20(%esp), %esi
	testl	%esi, %esi
	jle	.L17
	movl	$0, %ebx
.L19:
	subl	$4, %esp
	.cfi_def_cfa_offset 20
	pushl	(%edi,%ebx,4)
	.cfi_def_cfa_offset 24
	pushl	$.LC3
	.cfi_def_cfa_offset 28
	pushl	$1
	.cfi_def_cfa_offset 32
	call	__printf_chk
	addl	$1, %ebx
	addl	$16, %esp
	.cfi_def_cfa_offset 16
	cmpl	%ebx, %esi
	jne	.L19
.L17:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE42:
	.size	printArray, .-printArray
	.section	.rodata.str1.1
.LC4:
	.string	"Enter length for the array"
	.section	.rodata.str1.4
	.align 4
.LC5:
	.string	"Now that it is made lets print it"
	.section	.rodata.str1.1
.LC6:
	.string	"Now we sort!:"
.LC7:
	.string	"\n and we will print it! "
	.text
	.globl	main
	.type	main, @function
main:
.LFB43:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$28, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	pushl	$.LC4
	call	puts
	addl	$8, %esp
	leal	-16(%ebp), %eax
	pushl	%eax
	pushl	$.LC2
	call	__isoc99_scanf
	addl	$4, %esp
	pushl	-16(%ebp)
	call	readArray
	movl	%eax, %ebx
	movl	$.LC5, (%esp)
	call	puts
	addl	$8, %esp
	pushl	-16(%ebp)
	pushl	%ebx
	call	printArray
	movl	$.LC6, (%esp)
	call	puts
	addl	$8, %esp
	pushl	-16(%ebp)
	pushl	%ebx
	call	sortArray
	movl	$.LC7, (%esp)
	call	puts
	addl	$8, %esp
	pushl	-16(%ebp)
	pushl	%ebx
	call	printArray
	movl	%ebx, (%esp)
	call	free
	addl	$16, %esp
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L23
	call	__stack_chk_fail
.L23:
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE43:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

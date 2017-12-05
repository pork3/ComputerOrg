findmin: #int findmin(int* arr, int length)
	pushl %ebp
	rrmovl %esp, %ebp
	pushl %ebx

	mrmovl 8(%ebp), %ecx
	mrmovl 12(%ebp), %edx

	rrmovl %ecx, %eax 


	irmovl 4, %ebx
	addl %ebx , %ecx #array[1]

	#back things up
	pushl %ecx
	push %eax

	mrmovl (%ecx) 


	popl %eax
	popl %ecx	


	popl %ebp
	ret




Main:
	pushl %ebp
	rrmovl %esp, %ebp
	#last argument is first
	irmovl $5, %eax
	pushl %eax
	irmovle array, %eax
	pushl %eax

	call findmin
	rrmovl %ebp, %esp
	popl %ebp
	ret
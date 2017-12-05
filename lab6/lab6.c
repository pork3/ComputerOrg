.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    call Main
    halt
    
    
add: #int a b
    pushl %ebp
    rrmovl %esp, %ebp
    
    mrmovl 8(%ebp),%eax
    mrmovl (%eax),%eax
    mrmovl 12(%ebp),%ecx
    mrmovl (%ecx),%ecx
    
    addl %ecx, %eax
    
    popl %ebp
    ret
    
    
    
mult: //int mult(int a int b)
    pushl %ebp
    rrmovl %esp, %ebp
    pushl %ebx
    mrmovl 8(%ebp),%eax
    rrmovl %eax , %edx //copy
    mrmovl 12(%ebp),%ecx
    irmovl $1 ,%ebx
    subl %ebx, %ecx
    je end
    
    loop:
        addl %edx, %eax
        
        jg loop
    end:
    popl %ebx
    popl %ebp
    ret
    
Main:
    pushl %ebp
    rrmovl %esp, %ebp
    
    
    irmovl array, %eax
    
    irmovl $2, %eax
    pushl %eax
    irmovl $3, %eax
    pushl %eax
    call add
    
    #stack cleanup
    rrmovl %ebp, %esp
    
    
    popl %ebp
    ret
    
.pos 0x100
Stack:
    






.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    call Main
    halt
    
    
swap: #int *a *b
    pushl %ebp
    rrmovl %esp, %ebp
    
    mrmovl 8(%ebp),%eax
    mrmovl (%eax),%eax
    mrmovl 12(%ebp),%edx
    mrmovl (%edx),%edx
    
    
    
    popl %ebp
    ret

	.align 4 	
pointers:
    .long 0x0001
	.long 0x0002

Main:
    pushl %ebp
    rrmovl %esp, %ebp
    
    
    //moving the addr not valu
    irmovl pointers, %eax
    mrmovl (%eax), %ecx
    irmovl $4, %edx
    addl %edx , %eax
    mrmovl (%eax) , %edx
    rrmovl %edx , %eax

    
    call swap
    
    #stack cleanup
    rrmovl %ebp, %esp
    
    
    popl %ebp
    ret
    
.pos 0x100
Stack:
    
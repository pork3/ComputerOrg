#include <stdio.h>

/*x8 , 12y , 16z
movl 12(%ebp), %edx  | int a = y get value from 12 offset from base pointer which is y and store in edx
subl 16(%ebp), %edx  | subtract z from y |  subtract value from 16 offset store in edx
movl %edx, %eax      | int b = y move value from edx to eax 
sall $31, %eax       | shift left value at eax or int b << by 31 
sarl $31, %eax        | shift right value at eax or int b >> 31
imull 8(%ebp %edx	| multiply edx by 8 or a *8
xorl %edx, %eax    | xor edx and eax vlaue in eax a^b


These comments above are my work shown, on the left is the assembly, right is my explanation and 
translation to c code

*/


int decode2(int x, int y, int z){
	int a = y - z;  // 
	int b = a; 

	b = b << 31;
	b = b >> 31;

	a = a* x;

	b = a^b;

}


int main(int argc , char ** argv)
{
	printf("%d\n",decode2(1,2,4));
	printf("%d\n",decode2(-4,-8,-12));

	return 0; 
}
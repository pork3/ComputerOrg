#include <stdio.h>

int main(int argc , char** argv)
{
	int result;

	asm_volatile__(

	"f:"
	"pushl %%ebp;"
	"movl %%esp, %%ebp"


	"movl 8(%%ebp), %%eax;"

	"popl %%ebp;"
	"retl;"
	:"=a"(result)

		);
/////////////////////////////CALL F BELOW ??????????????
//move esp down stack by 4 (call ) ebp points to top
//because esp is pointer can dereference
//pushl is a subl of 4 from esp
//then move a into the value pointed to by esp
	//

//
		asm_volatile__(

	"pushl $1";
	"call f;"
	"addl $4 %%esp"

	:"=a"(result));




	return 0;
}
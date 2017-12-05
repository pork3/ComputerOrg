#include<stdio.h>

int leftShift(int a , int b){

	return a << b; clear
}



int main (int argc , char** argv)
{
int i;
int result 0;
	for (i =0; i < 10; i++){
		result +=i;
	}

	while(i < 10){
		result+=i;
		i++;
	}

	//goto

	loop:
		result +=1;
		i++;
		if(i <=10){
			goto loop;
		};



	asm_volatile__(
	"molv $10 %%eax;": "=a"(result)); // = specifies output a means output regist with middle a, and whatever is in there put the variable



	"movl $0, %%ecx;"

	"movl $0, %%eax;"
	"loop:"
	"addl, %%ecx ,eax; "
	"loop:"
	"addl, %%ecx , %%eax;"
	"addl $1 , %%ecx";
	"cmpl $10, %%ecx"
	"jle"


	printf("%d", result);

	return 0; 
}
#include <stdio.h>

unsigned int count(unsigned long x ){
	int len = sizeof(x);
	int result = 0;
	char *ptr = &x;

	for(int i = 0; i < len; i++){
		if(*(ptr + i) > 0)
			result++;
	}
	return result; 
}


unsigned int countNonEmptyBytes(unsigned long x ){

	unsigned int count  = 0;

	for(int i = 0; i < sizeof(x); i ++)
	{
		if (x >> (8*i) & 0xFF)
			count++;
	}

	return count; 
}

unsigned int countbytes2(unsigned long x)
{
	unsigned int result = 0;

	for(int i =0; i < sizeof(x); i++)
	{ 
		result+= (x >> (8*i)) & 1;
	}
}


int main(int argc , char** argv ){

	//printf("%d\n" , 1&0);
	printf("count is : %d\n", count(0x110022) );
}
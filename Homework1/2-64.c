#include <stdio.h>

int any_odd(unsigned x){
	unsigned oddMask = 0xAAAAAAAA;

	return (x & oddMask) !=0;
}

int main(int argc , char** argv){

	printf("0X2 : %X \n " , any_odd(0X2));
	printf("0X3 : %X \n ", any_odd(0X3));
	printf("0XFFFFFFFF : %X \n ", any_odd(0XFFFFFFFF));
	printf("0x55555555 : %X \n", any_odd(0x55555555));
	//printf("%X", (0xAAAAAAAA & 0x2));
	return 0; 
}

//10 10 10 10 
//11 11 11 11 
//_&____________
//10 10 10 10 

//0xaaaaaaaa 10 10 10 10
//even set to 1
//0x55555555
//odd set to 1 01 01 01 01 


//10 10 10 10 xaa
//&
//01 01 01 01 0x55
//___________
//00 00 00 00 if 0 and 
//0 all even bits  






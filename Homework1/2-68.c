#include <stdio.h>

int lower_one_mask(int n){
	
	int mask = (1 << n) - 1;

	return mask; 

}

int main(int argc , char** argv){

	//printf("%X \n ", lower_one_mask(2) );


	printf("1 : %d \n" , lower_one_mask(1));
	printf("2 : %d \n" , lower_one_mask(2));
	printf("3 : %d \n " , lower_one_mask(3));
	printf("5 : %d \n ", lower_one_mask(5));
	return 0; 
}

/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 
--
> 0x3
F, n = 17 
--
> 0x1FFFF
* Assume 1 <= n <= w
*/
// n - 1
// 00 00 00 01 
// 00 00 00 


//and of 1 and x is x
//and of o and x is 0 





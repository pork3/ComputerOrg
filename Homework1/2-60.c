#include<stdio.h>

unsigned replace_byte (unsigned x, int i, unsigned char b)
{
	unsigned shift = i *8;        // x 12 34 56 78  when i =2 replace 34

	unsigned mask = (0xff) << shift;// 00 ff 00 00 

	return x = (x & (~mask)) | (b << shift)  ; // get rid of 0's

	//b = b << shift;

	// return x; 
  
}

int main(int argc, char**argv)
{
	printf("%X Original value \n", 0x12345678);
	printf("2__________ %X\n", replace_byte(0x12345678, 2 , 0xab)) ;
	printf("0___________%X\n" ,replace_byte(0x12345678, 0 , 0xab));
	printf("3____________%X\n", replace_byte(0x12345678, 3 ,0xab));
	printf("900____________%X\n", replace_byte(0x12345678, 900, 0xab)); //900 mod 8 == 4
	printf("4_______________%X\n",replace_byte(0x12345678, 4, 0xab) );
	return 0;
}

/* Suppose we number the bytes in a w
-
bit word from 0 (least significant) to w/8 − 1 (most 
significant). Write code for the following C function, which will return an unsigned value 
in which byte i
of argument x has been replaced by byte b: */

//0x12ab5678


// 00 ff 00 00 
// 12 34 56 78 &
//________________
// 12 	
	// 00 ab 00 00 

//after mask  0x12345678 = 0x 00340000
		

//b                        0x 00ab0000
				//		~mask ff00ffff

					//     0x 12345678
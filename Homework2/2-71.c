#include <stdio.h>

typedef unsigned packed_t;  //data type where 4 bytes are packed 

////// Part A ///////////
/*
	The program does not work with negative numbers it drops the sign on the mask
*/
///////////////////////

int xbyte(packed_t word , int byteNum){

	//get index and shift word
	int to_signed = word << ((3-byteNum) << 3);

	return (to_signed >> 24 ); //exted
}

int failed(packed_t word , int byteNum){

	return (word >> (byteNum << 3)) & 0xFF; 
}


int main(int argc , char** argv){

	printf("Hey look I work with negatives now\n");

	printf("fixed produces: ______ %X \n", xbyte(0x00007700, 1));
	printf("fixed produces : _______ %X \n", xbyte(0x00ee0000,2));

	return 0; 
}

/* 4 SIGNED into 32 UNSIGNED 
bytes are numberd 0 (least) to 3 most

using 2 compliment arithmetic and arithmetic right shift



11 11 11 11 


00 00 00 11 << 3
00 01 10 00 


*/


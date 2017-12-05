#include <stdio.h>
#include <stdlib.h>

#define CACHEBLOCKSIZE 16 //const for size for size of cache block needed
#define INTSIZE 4 //I use it multiple times, easier just to define, also more portable for 64 bit or longs etc???

typedef struct {
	unsigned char isValid : 1; //char for valid block check
	unsigned int bitTag :26;
	unsigned char value[INTSIZE];
} CacheBlock;

void PrintHexValue(unsigned char *value, int length){
	int i; //get values and print as hex
	for(i=0 ; i < length; i++){
		printf("%X " , value[i]);
	}
	printf("\n");
}

//function to set up the parts of the cache block
void PartitionAddress(unsigned hexAddress, unsigned int *addressp){ 
	addressp[0] = (hexAddress >> 6); //26 bits , shift 6 32-6
    addressp[1] = ((hexAddress & 0x0000003C) >> 2); //need bits 6 - 2, so and with this mask 
    addressp[2] = (hexAddress & 0x00000003); // need bits 0 - 1 and it with this mask///////
}
//actually other way around... int to char 
void CharacterArraytoInt(unsigned char *val , unsigned int value ){
	int i ; 
	int shift = 24; //shift variable to get bits we want
	for (i =0; i < INTSIZE ; i++){
		val[i] = (value >> shift) & 0xFF; //get bits we want and goodbye to rest
		shift-=8; 
	}
}

unsigned int TagValue(unsigned char *cacheVal , unsigned int givenval){
	int i;
	unsigned int shift = 24;
	unsigned mask = 0xFFFFFFFF; 	
	for (i= 0 ; i < INTSIZE ; i++){
		unsigned number = cacheVal[i] & mask << shift;
		shift -=8;
	} 
	return number; 
}

void Read(CacheBlock* cacheblock , unsigned int hexAddress , unsigned int *addressp ){
	//CHECK LOGIC
	PartitionAddress(hexAddress , addressp);
	unsigned int cacheIndex = addressp[1];//created vars for readability
	unsigned int cacheTag = addressp[0];
	printf("Looking for index : %X\n", cacheIndex); //stuff we are looking for
	printf("Looking for tag : %X\n" , cacheTag);

	unsigned bitval = TagValue(cacheblock[cacheIndex].value, cacheTag);
	printf("func %X\n", bitval);
	printf("direct %X\n", cacheTag);

	if(cacheblock[cacheIndex].isValid && cacheblock[cacheIndex].bitTag == cacheTag){
	printf("HIT\n");//it's found if the stuff matches
	PrintHexValue(cacheblock[cacheIndex].value, INTSIZE);
	} 
	else if(!cacheblock[cacheIndex].isValid) //not set up yet
	{
	 	printf("Miss, cache is still cold, maybe warm it up \n");
	}else{ 
		printf("Tag mismatch/something else went wrong\n");
	}
}

void Print(CacheBlock* cacheblock){
	int i;
	for (i=0; i < CACHEBLOCKSIZE ; i++){
		if (cacheblock[i].isValid){
			printf("Set index : %d\n", i ); //set index is same as iterator
			printf("Cache tag : %X\n" , cacheblock[i].bitTag);
			PrintHexValue(cacheblock[i].value, INTSIZE);
		}
	}
}

void Write(CacheBlock* cacheblock , unsigned int hexAddress , unsigned int value, unsigned int *addressp ){
	PartitionAddress(hexAddress , addressp); //partition the address get needed parts
	//lookup cacheblock of index
	unsigned int cacheIndex = addressp[1]; //get index from the address partition
	unsigned int cacheTag = addressp[0];

	if (cacheblock[cacheIndex].isValid){
		//isvalid is true, kick whatever lives there out
		printf("Someone got evicted!!!!!!");
		printf("The current index is : %X\n" , addressp[1]); //index will be the same regardless 
		printf("The current tag is : %X\n", cacheblock->bitTag); //get tag
		printf("The value of the current cacheblock is : "); //get value
		PrintHexValue(cacheblock[cacheIndex].value, INTSIZE); //print the value at current block
		CharacterArraytoInt(cacheblock[cacheIndex].value, value ); //overwrite value
		cacheblock->bitTag = cacheTag; //overrite tag

	}else{
		//if isvalid is false
		cacheblock[cacheIndex].isValid = 1;
		printf("The cacheblock who lives here now has this info\n");
		printf("The index of the address who lives here is : %X \n" , cacheIndex);
		printf("The tag of the address who lives here is : %X \n" , cacheTag);
		cacheblock[cacheIndex].bitTag = cacheTag;
		printf("The value is now : %X\n", value); //we are going to override the value so
		CharacterArraytoInt(cacheblock[cacheIndex].value, value ); //this wont work , but dummy code until i make a conversion func
	}
}


int main(int argc , char** argv){
	unsigned char running = 1; //bool to exit program
	unsigned char userInput; //r,w/p,q
	unsigned hexAddress;
	unsigned int addressValue; 
	unsigned int addressTIO [3];// array to hold tag index offset
	CacheBlock* cache = malloc( CACHEBLOCKSIZE * sizeof(CacheBlock)); //allocate enought memory for cache block
	int i;
	for (i=0 ; i < CACHEBLOCKSIZE ; i++){
		cache[i].isValid = 0; //initialize valid to false
	}
	
	while(running)
	{
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit:");
		scanf("%c", &userInput);
		switch(userInput){
			case 'r':
				printf("Enter a hex address to read : ");
				scanf("%X" ,&hexAddress );
				//call a read function
				Read(cache, hexAddress , addressTIO);
				break;
			case 'w':
				printf("Enter a hex address to write to : \n");
				scanf("%X", &hexAddress);
				printf("Enter a value for the address");
				scanf("%X", &addressValue);
				Write(cache,hexAddress , addressValue, addressTIO );
				break;
			case 'p':
				Print(cache);
				//call print function 
				break;
			case 'q':
				printf("Quiting program...");
				free(cache);
				running = 0;
				break;
			default:
				printf("Unknown/invalid input");
				break;
			}		
	}

	return 0;
}
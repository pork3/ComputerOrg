# include<stdio.h>
# include<string.h>
/* copy an integer val into a buffer buf, 
but it should do so only if enough space is available in the buffer */


////////////////PART A ////////////////////
/* sizeof always returns a type of size_t which is a unsigned number, when there is a signed vs unsigned comparison
this will always be greater than 0*/
///////////////////////////////////////////

void copy_int(int val, void *buf, int maxbytes) {
	
	//cast size of to int to solve the unsigned singed issue

	if (maxbytes-(int)sizeof(val) >= 0){
		printf("I ran for values %d and %d\n", val,maxbytes);
		memcpy(buf, (void *) &val, sizeof(val));}
	else
		printf("I DID NOT RUN for values %d and %d\n", val,maxbytes);
} 

int main(int argc , char** argv){

	int buffer [10];

	copy_int(42, buffer , 4);

	copy_int(42, buffer , 2);



	return 0 ;
}
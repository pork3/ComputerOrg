#include <stdio.h>

int loop(int x , int n){
	int result = -1;

	for (int mask = 1 ; mask != 0 ; mask = mask << n ){
		result ^= (x & mask);
	}
	return result; 
}


int main(int argc , char** argv){
	
	printf("%d\n" , loop(1,1));

	printf("%d\n", loop(3,1));

}
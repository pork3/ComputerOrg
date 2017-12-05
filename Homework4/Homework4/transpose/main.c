#include <stdio.h>

#define M 13
typedef int Marray_t[M][M];

void transposebetter(Marray_t A){
    int i, j; //row/col
    int * temp; 
    for(j = 0; j < i ; j++)
    {

    	*temp = *(*(A+i)+j); //get value at offset j
  //  	printf("%d\n", *(*(A+i)+j));
  //  	printf("%d\n",  *(*(A+j) + i));
    	*(*(A+i)+j) = *(*(A+j) + i); //put j into i
    	*(*(A+j)+i) = *temp; //set value to temp
    	j + (4*M); //get next 
    }
}

void transpose(Marray_t A) {
    int i, j;
    int *start = &A[0][0];
    for (i=0; i<M; i++) {
        for (j=0; j<i; j++) {
            int* y = start + ((i*M)+j);
            int* u = start + ((j*M)+i);
            int temp;
            temp = *y;
            *y = *u;
            *u = temp;
        }
    }
}

void printarray(Marray_t A){
	int i , j; 
	for(i = 0; i < M ; i++){
		for (j = 0; j < M ; j++){
			printf("%5d ", A[i][j] );
		}
		printf("\n");
	}
}


int main (int argc , char** argv){
	Marray_t t = {{1,2,3,4,5,6,7,8,9,10,11,12,13}
				};

	printarray(t);
	printf("After transposing \n");
	transposebetter(t);
	printf("\n");
	printarray(t);


}
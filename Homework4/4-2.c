#include <stdio.h>

#define M 13
typedef int Marray_t[M][M];


// this is the final version I attempted to make it a single loop at first, but 
//didnt have any luck, that is why some of the stuff is commented out and it 
//doesnt look good 

void transposebetter(Marray_t A){
   int * temp; 
    for(int i = 0; i <M ; i++) //j will never be less than i 
    {
    	for(int j =0; j <i ; j++){
    	*temp = *(*(A+i)+j); //get value at offset j
   		//printf("%d\n jjjjj", *(*(A+i)+j)); *** testing values to make sure
   		//printf("%d\n iiii",  *(*(A+j) + i));
    	*(*(A+i)+j) = *(*(A+j) + i); //put j into i
    	*(*(A+j)+i) = *temp; //set value to temp
    	//j += (4*M); //get next 
    	//i+= M; my attempt when it was a single loop 
    	}

    }

}

//an attempt that worked , not 100%
/*
void transposebettersecond(Marray_t A){
	int *ebx= &A[0][0]; //set up pointer to array
	int* temp; //temp variable 
    for (int i=0; i<M; i++) 
    {
       for (int j=0; j<i; j++) 
       {
            int* row = ebx + ((i*M)+j); //offset j
            int* col = ebx + ((j*M)+i); //offset i 
            *temp = *row;
            *row = *col; 
            *col = *temp; 
        }
    }
}*/

void printarray(Marray_t A){
	int i , j; //printing an array without pointer arithmetics
	for(i = 0; i < M ; i++){
		for (j = 0; j < M ; j++){
			printf("%5d ", A[i][j] );
		}
		printf("\n");
	}
}

void populatearray(Marray_t A)
{				//not optimized for loop to populate array
	int p = 1;
	int count = 0;
	for (int i =0; i < M ; i++)
	{
		for(int j =0 ; j < M ; j++)
		{		
			A[i][j] = p;
			count++;
			if(count % M == 0)
				p++;
		}
	}
}


int main (int argc , char** argv){
	Marray_t t;;

	populatearray(t);
	printarray(t);
	printf("After transposing \n");
	transposebetter(t);
	printf("\n");
	printarray(t);


}


/*
****** this page helped a lot understanding pointer arithmetic in 2d arrays 
https://stackoverflow.com/questions/13554244/how-to-use-pointer-expressions-to-access-elements-of-a-two-dimensional-array-in*/
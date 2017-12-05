# include <stdio.h>
# include <stdlib.h>

int *readArray(int count){

	//create an int array based on user input
	//storing on heap with malloc3
	int* userArray = malloc(sizeof(int) *count);

	printf("Enter some numbers to populate this array\n");
	for(int i=0; i < count; i++)
	{
		printf("Enter a number: \n");
		scanf("%d", &userArray[i]);
		//takes input from the user and stores in the array
	}

	return userArray; 
}

void swap(int*xp, int*yp){
	//standard swap with a temp variable
	int temp = 0;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapl(int*xp, int*yp){
	*xp ^= *yp; //xor swap zach showed in lab
	*yp ^= *xp;//actually pretty neat
	*xp ^= *yp;
}

void sortArray(int*array,int length){

	int min,j,i;
	//standard selection sort but passing in the address of the values
	// of the array elements if needed to swap because ponters
	for(i = 0; i < length-1; i++){
			min =i;
		for(j = i+1 ; j < length ; j++)
		{
			if(array[j] < array[min])
				min = j;
		}
		if( min != i)
			swapl(&array[i], &array[min]);
	}
}

void printArray(int *array, int length){
	for(int i =0; i < length; i++)
	{
		printf("%d ", array[i] );
	}
	//printing an array using a for loop and the index of the array
}


int main(int argc , char** argv){

	printf("Enter length for the array\n");
	int n; 
	scanf("%d", &n); //getting user input

	int* userArray = readArray(n); //creating an array for the user to work with
	printf("Now that it is made lets print it\n");
	printArray(userArray, n);

	printf("Now we sort!:\n");
	sortArray(userArray,n);
	printf("\n and we will print it! \n");
	printArray(userArray,n);
	free(userArray); //frees up the memory from malloc


	return 0; 
}
//looked at this page as a reminder of how a selection sort works
//https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm/
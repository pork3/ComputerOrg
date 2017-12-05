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
void swapl(int*xp, int*yp){
	//standard swap with a temp variable
	int temp = 0;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
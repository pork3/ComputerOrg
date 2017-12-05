# include<stdio.h>
# include<stdlib.h>

void printArray(int* a, int size)
{
	int i;
	for(int i=0; i < 5; i++)
	{
		printf("a[%d] = %d\n" , i, *(a+i));
	}
}

void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a; 
	*a ^= *b; //dealing with memory location so must dereference s
}


int main(int argc , char** argv)
{
	int a* = malloc(sizeof(int)*5);
	//int* b = &a; 	

	//printf("%d\n", *b );
	//printf("%d\n",b[0]); //a pointer an an array of one element are one element

	swap(&a,&b);
	//int a[1];

	//for(int i = 0; i < 5, i++)
	//{
		
	/////}

	//printf("%d\n", );

	printf("Enter size: ");
	scanf("%d", &size);

	free(a);
	return 0; 
}
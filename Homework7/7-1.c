#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define VECTOR_SIZE 100000




void inner(float *u , float *v , int length , float *dest)
{
	int i;
	float sum = 0.0f;

	for (i =0; i < length; i++)
	{
		sum += u[i] * v[i];
	}
	//printf("sum %f\n" , sum);
	*dest = sum; 
}

//with 4 way lsum += u[i] * v[i];oop unrolling
void inner2(float *u , float *v , int length , float *dest)
{
	int i;
	//parallel acc
	float sum = 0.0f;
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;

	for (i =0; i < length; i+= 4)
	{
		sum += u[i] * v[i]; //first , second, etc elements
		sum1 += u[i+1] * v[i+1];
		sum2 += u[i+2] * v[i+2];
		sum3 += u[i+3] * v[i+3];
	}

	for(; i < length ; i++)
	{//cleanup any leftovers
		sum +=u[i] *v[i];
	}

	*dest = sum + sum1 + sum2 + sum3; 


}

int main(int argc, char**argv)
{
	float *u = malloc(sizeof(float) * VECTOR_SIZE); //set up u/v
	float *v = malloc(sizeof(float) * VECTOR_SIZE);
	float sum = 1.0f; //set up dest
	float* dest = &sum;
	long long elapsed;
	int i;

	for(i=0 ; i < VECTOR_SIZE; i++)
	{
		*(u +i) = 1.0f *i; //populate the arrays
		*(v+i) = 1.0f* i;
	}

	struct timeval start; //timetesting from class example
	gettimeofday(&start, NULL);

	inner(u,v,VECTOR_SIZE,dest);
	
	struct timeval current;
	gettimeofday(&current, NULL);

	elapsed = (current.tv_sec - start.tv_sec)*1000000LL + (current.tv_usec - start.tv_usec);
	printf("%f\n", elapsed/1000000.0);

	dest = &sum; //reset the sum, trying to make them as close as possible 

	struct timeval startwopt;
	gettimeofday(&startwopt, NULL);

	inner2(u,v,VECTOR_SIZE,dest);


	struct timeval currentwopt;
	gettimeofday(&currentwopt, NULL);

	elapsed = (currentwopt.tv_sec - startwopt.tv_sec)*1000000LL + (currentwopt.tv_usec - startwopt.tv_usec);
	printf("%f\n", elapsed/1000000.0);

	free(u);
	free(v);

}
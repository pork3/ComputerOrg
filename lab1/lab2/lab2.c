#include<stdio.h>

unsigned f2u(float f){
	return *((unsigned*)&f);
}

unsigned f2uh(float f){

	typedef union{
		float f; 
		unsigned u;
	}  u;

	u u1;
	u1.f = f;

	return u1.u;
}

int main(int argc , char** argv){

	//Schar ch = 7;
	//float ch = 8.0;
	//for(int =31 ; i >=0 ; i--){
	//	printf("%f ", ch >> i & 1 );
	//}

	signed int s = 0xFFFFFCE6;

	printf("%d", s);

	return 0; 
}
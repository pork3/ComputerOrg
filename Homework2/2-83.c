#include <stdio.h>

unsigned f2u(float f);

int float_le(float x, float y) {    
     unsigned ux = f2u(x);     
     unsigned uy = f2u(y); 

     /* Get the sign bits */     
     unsigned sx = ux >> 31;     
     unsigned sy = uy >> 31;     
     
     //ux << 1 <= uy <<1; 
     //break into separate cases instead of trying everything at once ...

     
     /* Give an expression using only ux, uy, sx, and sy */ 
     return ( ux << 1 == 0 && uy << 1 == 0 || sx && !sy //bbobth x or x greater than 0 y greater or equal
     || (!sx && !sy && ux <= uy) || // x greater 0 , y greater than 
      sx && sy && ux >= uy); // bboth greater than 0 
     }


unsigned f2u(float f) {

    return *((unsigned*)&f); 
}
// ux is less than or equal to uy

void print_bitsa(unsigned u ){

    for(int i = (sizeof(u) << 3) ; i -- ; i >=0){

        printf("%d", (u >> i & 1)); 
    }
    printf("\n");
}



int main (int argc , char** argv){



    printf("%d\n",float_le(-1.0f, 1.0f));
    printf("%d\n",float_le(-0.0f, 0.0f));
    printf("%d\n",float_le(-2.0f, 10.0f));
    printf("%d\n",float_le(45.5f, 10.0f));
    printf("%d\n",float_le(15485.515f, 15.0f));
    printf("%d\n",float_le(1.0f, -1.0f));
    printf("%d\n",float_le(1.0f, -1.0f));


    return 0;
}


/*

00000000000000000000000000000101 //unsgined representation of 5

0 10000001 01000000000000000000000 // float representation of 5 

/// first is less than second



////////////////*/
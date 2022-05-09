// Modified by Juan Carlos Juárez

// d) Heap memory for "x", "y" and "z". To use malloc/free, remember to add the following 

#include<stdlib.h>
#include<stdio.h> 
#include<stdint.h>

int32_t main() 
{ 
    int32_t* x = (int32_t*)malloc(sizeof(int32_t));
    int32_t* y = (int32_t*)malloc(sizeof(int32_t));
    int32_t* z = (int32_t*)malloc(sizeof(int32_t));
    *x = 20;
    *y = 30;
    *z = 40;
    printf("x = %d, y = %d, z = %d\n", *x, *y, *z); 
    *z = *z + *x + *y;
    printf("x = %d, y = %d, z = %d\n", *x, *y, *z); 
    free (x);
    free (y);
    free (z);
  return 0; 
}

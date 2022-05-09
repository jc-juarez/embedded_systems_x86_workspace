// Modified by Juan Carlos Juárez

// b) Persistent memory for "x", "y" and "z"  (global scope)

#include<stdlib.h>
#include<stdio.h> 
#include<stdint.h>
 
int32_t x = 20;
int32_t y = 30;
int32_t z = 40;

int32_t main() 
{ 
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
    z = z + x + y;
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
      
  return 0; 
}

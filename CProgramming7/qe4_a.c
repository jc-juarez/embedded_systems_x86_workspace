// Modified by Juan Carlos Juárez

// a) Program memory for "x", "y" and stack memory for "z" 

#include<stdlib.h>
#include<stdio.h> 
#include<stdint.h>
 
const int32_t x = 20;
const int32_t y = 30;

int32_t main() 
{ 
    int32_t z = 40;
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
    z = z + x + y;
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
      
  return 0; 
}

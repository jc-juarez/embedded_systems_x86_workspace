// Modified by Juan Carlos Juárez

// c) Persistent memory for "x", "y" and "z" (local scope, static keyword)

#include<stdlib.h>
#include<stdio.h> 
#include<stdint.h>

int32_t main() 
{ 
    static int32_t x = 20;
    static int32_t y = 30;
    static int32_t z = 40;
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
    z = z + x + y;
    printf("x = %d, y = %d, z = %d\n", x, y, z); 
      
  return 0; 
}

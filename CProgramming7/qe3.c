// This code will throw an error because static is not initialized with a constant value.

#include<stdio.h> 
#include <stdint.h>

int32_t initializer(void) { 
    return 50; 
}    
int32_t main() { 
    static int32_t i = initializer(); 
    printf(" value of i = %d", i); 
    getchar(); 
    return 0;
}

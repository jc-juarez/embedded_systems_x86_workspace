#include <stdio.h>
#include <stdint.h>
#define SUM(a,b) (a + b)
 
/* 
QE1
Using the sizes defined in QE2, write your own definition of the following types 
EMBuint8
EMBuint16
EMBuint32
EMBint8
EMBint16
EMBint32
EMBfloat32
EMBfloat64
*/
typedef unsigned char EMBuint8;
 
/* 
QE2
Add the 6 lines to print 6 integer types: char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, float, double, long long, unsigned long long.
Also write code to print all the fixed-width types presented in class: int8_t,  
uint8_t , etc. */
 
 
int main() {
    int i, y; 
    printf("\n\r Size of char is %ld", sizeof(char));
    printf("\n\r Size of int is %ld", sizeof(int));
    printf("\n\r Size of long is %ld", sizeof(long));
 
/*
QE3 Write the printf statement to print the size in bytes of each of previously defined types.
*/
 
printf("\n\r Size of EMBuint8 is %ld", sizeof(EMBuint8));
 
/*
QE4 Modify this code to remove the magic number
*/
uint32_t data_array[5] = {0,1,2,3,4};
for (i=0; i<5; i++){
    printf("\n Value is %d", data_array[i]);
}
 
/*
QE5  Lines of code to call the SUM macro
*/
y = 5 * SUM(4, 5) ;
printf("\n y = %d", y);
 
/* End of main program */
    getchar();
    printf("\n");
    return(0);
}

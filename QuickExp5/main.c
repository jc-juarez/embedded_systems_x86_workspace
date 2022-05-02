// Embedded Systems
// Quick Experiment 5
// Modified by Juan Carlos JUárez

#include <stdio.h>
#include <stdint.h>
#define SUM(a,b) (a + b)
#define NUMBER_OF_ITERATIONS 5
 
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

void QE2() {
    printf("\n\n*** QE2 - Data Types ***");
    char c = 127;
    unsigned char uc = 255;
    short s = 32767;
    int i = 2147483647;
    unsigned int ui = 4294967295;
    long l = 2147483647;
    unsigned long ul = 4294967295;
    float f = 2.54;
    double d = 2.5414;
    long long ll = 9999999999;
    unsigned long long ull = 99999999999;
    printf("\n\nChar: %d | Size is: %ld\n",c,sizeof(c));
    printf("Unsigned Char: %d | Size is: %ld\n",uc,sizeof(uc));
    printf("Short: %d | Size is: %ld\n",s, sizeof(s));
    printf("Integer: %d | Size is: %ld\n",i, sizeof(i));
    printf("Unsigned Integer: %u | Size is: %ld\n",ui, sizeof(ui));
    printf("Long: %ld | Size is: %ld\n",l,sizeof(l));
    printf("Unsigned Long: %lu | Size is: %ld\n",ul, sizeof(ul));
    printf("Float: %f | Size is: %ld\n",f, sizeof(f));
    printf("Double: %lf | Size is: %ld\n",d, sizeof(d));
    printf("Long Long: %lld | Size is: %ld\n",ll, sizeof(ll));
    printf("Unsigned Long Long: %llu | Size is: %ld\n\n",ull, sizeof(ull));
    int8_t i8 = 127;
    int16_t i16 = 32767;
    int32_t i32 = 2147483647;
    int64_t i64 = 9999999999;
    uint8_t ui8 = 255;
    uint16_t ui16 = 65535;
    uint32_t ui32 = 4294967295;
    uint64_t ui64 = 99999999999;
    printf("Integer 8 Bits: %d | Size is: %ld\n",i8, sizeof(i8));
    printf("Integer 16 Bits: %d | Size is: %ld\n",i16, sizeof(i16));
    printf("Integer 32 Bits: %d | Size is: %ld\n",i32, sizeof(i32));
    printf("Integer 64 Bits: %li | Size is: %ld\n",i64, sizeof(i64));
    printf("Unsigned Integer 8 Bits: %d | Size is: %ld\n",ui8, sizeof(ui8));
    printf("Unsigned Integer 16 Bits: %d | Size is: %ld\n",ui16, sizeof(ui16));
    printf("Unsigned Integer 32 Bits: %u | Size is: %ld\n",ui32, sizeof(ui32));
    printf("Unsigned Integer 64 Bits: %lu | Size is: %ld\n",ui64, sizeof(ui64));
}

void QE3() {
    printf("\n\n*** QE3 - Typedefs ***");
    typedef unsigned char JCuint8;
    typedef unsigned short JCuint16;
    typedef unsigned int JCuint32;
    typedef char JCint8;
    typedef short JCint16;
    typedef int JCint32;
    typedef float JCfloat32;
    typedef double JCfloat64;
    printf("\n\n\r Size of JCuint8 is %ld", sizeof(JCuint8));
    printf("\n\r Size of JCuint16 is %ld", sizeof(JCuint16));
    printf("\n\r Size of JCuint32 is %lu", sizeof(JCuint32));
    printf("\n\r Size of JCint8 is %ld", sizeof(JCint8));
    printf("\n\r Size of JCint16 is %ld", sizeof(JCint16));
    printf("\n\r Size of JCint32 is %ld", sizeof(JCint32));
    printf("\n\r Size of JCfloat32 is %ld", sizeof(JCfloat32));
    printf("\n\r Size of JCfloat64 is %ld", sizeof(JCfloat64));
}
 
 
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
uint32_t data_array[NUMBER_OF_ITERATIONS] = {0,1,2,3,4};
for (i=0; i<NUMBER_OF_ITERATIONS; i++){
    printf("\n Value is %d", data_array[i]);
}
 
/*
QE5  Lines of code to call the SUM macro
*/
y = 5 * SUM(4, 5) ;
printf("\n y = %d", y);


// QE2

QE2();

// QE3

QE3();
 
/* End of main program */
    getchar();
    printf("\n");
    return(0);
}

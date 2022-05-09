#include<stdio.h> 
#include<stdint.h>
 
uint32_t f1() { auto uint32_t a ; a = 0; a = a + 1; return a; }
uint32_t f2() {static uint32_t s ; s = 0; s = s + 1; return s; }
 
uint32_t f3() { auto uint32_t a = 0 ; a = a + 1; return a; }
uint32_t f4() {static uint32_t s = 0 ; s = s + 1; return s; }
 
uint32_t main() {
    printf("f1(): %d %d %d\n", f1(), f1(), f1()) ;
    printf("f2(): %d %d %d\n", f2(), f2(), f2()) ;
    printf("f3(): %d %d %d\n", f3(), f3(), f3()) ;
    printf("f4(): %d %d %d\n", f4(), f4(), f4()) ;
    return 0 ;
    } 

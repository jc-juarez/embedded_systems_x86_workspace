#include <stdio.h>
#include <stdint.h>

#define Array_Size_Uint8 48
#define Array_Size_Uint16 24
#define Array_Size_Uint32 12

uint8_t Array_uint8[Array_Size_Uint8] = {
                        0x20, 0x19, 0xFA, 0x22, 0x10, 0x02, 0x00, 0x00, \
                        0x28, 0x14, 0x24, 0x02, 0x01, 0xB4, 0x08, 0xAA, \
                        0x21, 0x17, 0x23, 0xBF, 0x16, 0x05, 0x15, 0x04, \
                        0x27, 0xAB, 0xFF, 0xA2, 0x00, 0x09, 0xBB, 0x11, \
                        0x22, 0x18, 0xF0, 0x24, 0xB2, 0x25, 0x26, 0xD4, \
                        0x29, 0x03, 0x13, 0x90, 0xE0, 0xCC, 0x12, 0x10  \
                        };

void printMemContent(void);
uint32_t sum(uint32_t, uint32_t);

int main() {
    int i;

/*
(Exercise Pointer arithmetic)
*/

    uint8_t* ptrTo8  = (uint8_t*) &Array_uint8[0];
    uint16_t* ptrTo16 = (uint16_t*) &Array_uint8[0];
    uint32_t* ptrTo32 = (uint32_t*) &Array_uint8[0];

    printf("ptrTo8 = %p\n", ptrTo8);
    printf("ptrTo16 = %p\n", ptrTo16);
    printf("ptrTo32 = %p\n\n", ptrTo32);

    ptrTo8 = ptrTo8 + 1;
    ptrTo16 = ptrTo16 + 1;
    ptrTo32 = ptrTo32 + 1;

    printf("ptrTo8 = %p\n", ptrTo8);
    printf("ptrTo16 = %p\n", ptrTo16);
    printf("ptrTo32 = %p\n\n", ptrTo32);

    ptrTo8 = ptrTo8 + 1;
    ptrTo16 = ptrTo16 + 1;
    ptrTo32 = ptrTo32 + 1;

    printf("ptrTo8 = %p\n", ptrTo8);
    printf("ptrTo16 = %p\n", ptrTo16);
    printf("ptrTo32 = %p\n\n", ptrTo32);

    printMemContent();

/*
(Exercise "const keyword")
*/
    const uint32_t c_value = 10;
    printf("c_value is: %u", c_value);


/*
(QE1) Obtain the pointer value for each of the examples found at slide 101 of 
      the "Cembedded" presentation. Print the pointer address before and after.
      justify the answers displayed by the printfs. 
*/
    // 32 Bit Pointer + 1
    uint32_t* ptr=(uint32_t*)1000;
    printf("\n\nptr is: %lu\n",(unsigned long) ptr);
    ptr=ptr+1;
    printf("ptr + 1 is: %lu\n\n",(unsigned long) ptr);

    // 32 Bit Pointer + 3
    uint32_t* ptr_plus3=(uint32_t*)1000;
    printf("ptr is: %lu\n",(unsigned long) ptr_plus3);
    ptr_plus3=ptr_plus3+3;
    printf("ptr + 3 is: %lu\n\n",(unsigned long) ptr_plus3);

    typedef struct abc {
        uint32_t* a;
        uint8_t* b;
        uint32_t* c;
    } ABC;

    // Struct Pointer
    ABC* ptr_struct = (ABC*)1000;
    printf("ptr is: %lu\n",(unsigned long) ptr_struct);
    ptr_struct = ptr_struct + 2;
    printf("ptr + 2 is: %lu\n\n",(unsigned long) ptr_struct);

/*
(QE2) Modify/add the code to illustrate the pre-inc, post-inc, pre-dec, post-dec
      operations (slide 103). Explain the difference with your own words
*/
    uint32_t qe2_var[3] = {10, 20, 30};
    uint32_t* qe2_ptr=(uint32_t*)&qe2_var[0];
    printf("\n\nWe start at position 0 which has the value of 10.\n");
    printf("If we do post increment it will remain the same for now...ptr is: %p and qe2_var is: %u\n", qe2_ptr, *(qe2_ptr++));
    printf("But now we see that it changed because it was done post....ptr is: %p and qe2_var is: %u\n", qe2_ptr, *(qe2_ptr));
    printf("But now if we do it pre it will change from this same line of code....ptr is: %p and qe2_var is: %u\n", qe2_ptr, *(++qe2_ptr));
    printf("The same goes for decrement, here we do post so it will decrement until the next line of code....ptr is: %p and qe2_var is: %u\n", qe2_ptr, *(qe2_ptr--));
    printf("Now here it goes back to 20....ptr is: %p and qe2_var is: %u\n", qe2_ptr, *(qe2_ptr));
    printf("And now here with pre it goes back to 10 in this same line....ptr is: %p and qe2_var is: %u\n\n", qe2_ptr, *(--qe2_ptr));

/*
(QE3) How do I extract the 0x33 value from variable “a” and place this value at temp?
Before
a = 0x22334455;
temp = 0x00;

After
a = 0x22334455;
temp = 0x22;

*/

// Here I will use both variables (I assume the proble refers to extracting value 0x33 and not 0x22 as shown in the example)

uint32_t a = 0x22334455;
uint8_t temp = 0x00;

// a) masks and bitwise operations

// We can do this in a quite simple way by just shifting and that's it
temp = (a >> 16);

printf("Masks and Bitwise Operations: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp);

// b)unions/structures

// Here we can do it even simpler (depends on what you like better) by using a simple union with a uint64 and a struct with 4 bit fields of 2 bytes each

union my_union {
    uint32_t base;
    struct {
        uint32_t first : 8,
                 second : 8,
                 third : 8,
                 fourth : 8;
    };
};

union my_union mu;
mu.base = a;
temp = mu.third;

printf("\nUnions and Structures: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp);

// c)variant access with pointer dereference

// As we know, we can create a pointer to this variable of type uint8_t and just add 2 so we get to the third uint8_t

uint8_t* ptr_8 = (uint8_t*)&a;
temp = *(ptr_8 + 2);

printf("\nPointer Dereference: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp);

// d)variant access with pointer subscripting

// This is the same as before, but now we use subscripting, which handles a pointer as an array

uint8_t* ptr_8_subs = (uint8_t*)&a;
temp = ptr_8_subs[2];

printf("\nPointer Subscripting: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp);

/*
(QE4) How do I extract the 0x2233 value from variable “a” and place this value at temp?
Before
a = 0x22334455;
temp = 0x00;

After
a = 0x22334455;
temp = 0x2233;

Using: 

*/

// a)masks and bitwise operations

// The same as before but now we save it in a uint16_t and just shift 16 bits

uint16_t temp_16 = (a >> 16);

printf("\nMasks and Bitwise Operations: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp_16);

// b)unions/structures

// The same as before but now our unions will be 16 bits each

union my_union_16 {
    uint32_t base;
    struct {
        uint32_t first : 16,
                 second : 16;
    };
};

union my_union_16 mu16;
mu16.base = a;
temp_16 = mu16.second;

printf("\nUnions and Structures: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp_16);

// c)variant access with pointer dereference

// The same as before but now the pointer will be uint16_t therefore the offset is just 1

uint16_t* ptr_16 = (uint16_t*)&a;
temp_16 = *(ptr_16 + 1);

printf("\nPointer Dereference: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp_16);

// d)variant access with pointer subscripting

// The same as before but now the pointer will be uint16_t therefore the offset is just 1 just as in dereferencing

uint16_t* ptr_16_subs = (uint16_t*)&a;
temp_16 = ptr_16_subs[1];

printf("\nPointer Dereference: \n");
printf("Variable 'a' is: %x\n", a);
printf("Variable 'temp' is: %x\n", temp_16);


/*
(QE5) Complete the code to execute the program by calling a function using 
      a function pointer
*/

    /*Calling function using function pointer */
    uint32_t(*func)(uint32_t, uint32_t) = sum;
    int32_t op1 = func(1, 2);

    /*Calling function in normal way using function name */
    int32_t op2 = sum(10, 13);

    printf("\nCalling pointer to func, sum is: %d\n", op1);
    printf("\nCalling function name, sum  is: %d\n\n", op2);



/* End of main program */
    return(0);
}

uint32_t sum(uint32_t num1, uint32_t num2){
    return(num1+num2);
}
void printMemContent(){
    int i;
    printf("%p :: ", &Array_uint8[0]);
    for(i=15;i>=0;i--) {
        printf("%02x ", Array_uint8[i]);
    }
    printf("\n%p :: ", &Array_uint8[16]);
    for(i=31;i>=16;i--) {
        printf("%02x ", Array_uint8[i]);
    }
    printf("\n%p :: ", &Array_uint8[32]);
    for(i=47;i>=32;i--) {
        printf("%02x ", Array_uint8[i]);
    }
    printf("\n");
}

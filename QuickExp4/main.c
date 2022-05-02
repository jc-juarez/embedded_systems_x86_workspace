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



int main() {
    int i;

/*
(QE1) Explain with a memory map, the output printed by the following lines of code */

    struct n_vals {
        uint32_t n2;
        uint32_t n4;
        uint16_t n3;
        uint8_t n1;
    };

    struct n_vals a;
    
    printf("Address of a.n1 is: %p\n", &(a.n1));
    printf("The size of struct n_vals is: %ld\n", sizeof(struct n_vals));
    printf("The size of a is: %ld\n", sizeof(a));



/*
QE2 Pointer fundamentals. What does the printf statement show? Explain and justify what each of the printf statements after each red statement.
*/
    uint8_t var = 0x10;
    uint8_t* ptr;
    uint8_t temp = 0x00;

    ptr = &var;
    printf("\nTemp is %x\n", temp);
    printf("var is %x\n", var);
    printf("ptr is %p\n", ptr);
    printf("*ptr is %x\n\n", *ptr);

    temp = *ptr;
    printf("Temp is %x\n", temp);
    printf("var is %x\n", var);
    printf("ptr is %p\n", ptr);
    printf("*ptr is %x\n\n", *ptr);

    temp = temp + 10;
    printf("Temp is %x\n", temp);
    printf("var is %x\n", var);
    printf("ptr is %p\n", ptr);
    printf("*ptr is %x\n\n", *ptr);

    *ptr = temp;
    printf("Temp is %x\n", temp);
    printf("var is %x\n", var);
    printf("ptr is %p\n", ptr);
    printf("*ptr is %x\n\n", *ptr);


/* 
(QE3) Complete the code to display: 
  a) What is the data type of Array?
  b) the hexadecimal addresses each 8-bit element of the Array_uint8.
  c) the hexadecimal value(data) located at each 8-bit element of the Array_uint8.
  d) What is the address of 0xcc? 
  e) What is the address of 0xbb? */


    printMemContent();

    printf("Address &array[%d] = %p \n",0, &(Array_uint8[0]));
    printf("Data array[%d]  = %x \n",0, Array_uint8[0]);
    printf("Address &array[%d] = %p \n", 1, &(Array_uint8[1]));
    printf("Data array[%d]  = %x \n",1, Array_uint8[1]);
    printf("Address &array[%d] = %p \n", 2, &(Array_uint8[2]));
    printf("Data array[%d]  = %x \n", 2, Array_uint8[2]);



/* 
(QE4) Complete the code to display: 
    a) What is the data type of Array?
    b) the hexadecimal addresses of each 16-bit element of the Array_uint16.
    c) the hexadecimal value(data) located at the 16-bit element of the Array_uint16.
    d) What is the address of 0x24f0? 
    e) What is the address of 0x11bb? */


    printMemContent();
    uint16_t* Array_uint16 = (uint16_t*) &Array_uint8[0];
    printf("Address &array[%d] = %p \n",0, &(Array_uint16[0]));
    printf("Data array[%d]  = %x \n",0, Array_uint16[0]);
    printf("Address &array[%d] = %p \n", 1, &(Array_uint16[1]));
    printf("Data array[%d]  = %x \n",1, Array_uint16[1]);
    printf("Address &array[%d] = %p \n", 2, &(Array_uint16[2]));
    printf("Data array[%d]  = %x \n", 2, Array_uint16[2]);



/* 
(QE5) Complete the code to display: 
    a) What is the data type of Array?
    b) the hexadecimal addresses of each 32-bit element of the Array_uint32.
    c) the hexadecimal value(data) located at the 32-bit element of the Array_uint32.
    d) What is the address of 0x24f0? 
    e) What is the address of 0x11bb? */


    printMemContent();
    uint32_t* Array_uint32 = (uint32_t*) &Array_uint8[0];
    printf("Address &array[%d] = %p \n",0, &(Array_uint32[0]));
    printf("Data array[%d]  = %x \n",0, Array_uint32[0]);
    printf("Address &array[%d] = %p \n", 1, &(Array_uint32[1]));
    printf("Data array[%d]  = %x \n",1, Array_uint32[1]);
    printf("Address &array[%d] = %p \n", 2, &(Array_uint32[2]));
    printf("Data array[%d]  = %x \n", 2, Array_uint32[2]);


/*
(QE6)
xxx020 :: aa 08 b4 01 02 24 14 28 00 00 02 10 22 fa 19 20
xxx030 :: 11 bb 09 00 a2 ff ab 27 04 15 05 16 bf 23 17 21
xxx040 :: 10 12 cc e0 90 13 03 29 d4 26 25 b2 24 f0 18 22

   Move the value 0x24f01822 from location xxx040 to xxx02C other values
   should be unchanged, use pointers and show the memory content after
   executing your code*/

uint32_t* ptr1 = (uint32_t*) 0x555555558040;
uint32_t* ptr2 = (uint32_t*) 0x55555555802C;

*ptr2 = *ptr1;

printMemContent();

/*
(QE7)
xxx020 :: aa 08 b4 01 02 24 14 28 00 00 02 10 22 fa 19 20
xxx030 :: 11 bb 09 00 a2 ff ab 27 04 15 05 16 bf 23 17 21
xxx040 :: 10 12 cc e0 90 13 03 29 d4 26 25 b2 24 f0 18 22

   Move the value 0x0900 from location xxx03C to xxx02C other values
   should be unchanged, use pointers and show the memory content after
   executing your code*/


/*
(QE8)
xxx020 :: aa 08 b4 01 02 24 14 28 00 00 02 10 22 fa 19 20
xxx030 :: 11 bb 09 00 a2 ff ab 27 04 15 05 16 bf 23 17 21
xxx040 :: 10 12 cc e0 90 13 03 29 d4 26 25 b2 24 f0 18 22

   Move the value 0xaa from location xxx02F to xxx04F other values
   should be unchanged, use pointers and show the memory content after
   executing your code*/



/* End of main program */
    return(0);
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

// Modified by Juan Carlos Juárez

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

/*
(QE1) Complete the code and explain the difference between pointer size
      and data type size 
*/

    int8_t *pc;
    int16_t *ps;
    void *pv;
    uint32_t *pi;
    
    printf("Size of pointer pc is: %ld\n", sizeof(pc));
    printf("Size of int8_t is: %ld\n", sizeof(int8_t));



/*
QE2 Rewrite the following code using a pointer to the structure.
*/

    struct inventory {
    uint8_t resistors;
    uint8_t capacitors;
    uint8_t leds;   
    };
    struct inventory var = {20,20,20};

    struct inventory* var_ptr = &var;
    
    printf("# of resistors is:  %d\n", var_ptr -> resistors);
    printf("# of capacitors is: %d\n", var_ptr -> capacitors);
    printf("# of leds is :      %d\n", var_ptr -> leds);

    var_ptr -> leds = var_ptr -> leds - 5;
    var_ptr -> resistors = var_ptr -> resistors - 4;

    printf("# of resistors is:  %d\n", var_ptr -> resistors);
    printf("# of capacitors is: %d\n", var_ptr -> capacitors);
    printf("# of leds is :      %d\n", var_ptr -> leds);

/* 
(QE3) Rewrite the previous item (QE2) using a datatype definition of a structure (using typedef)
*/

    printf("\nStruct with typedef (juan_struct):\n\n");

    typedef struct {
        uint8_t resistors;
        uint8_t capacitors;
        uint8_t leds;   
    } juan_struct;

    juan_struct juan = {20,20,20};

    juan_struct* juan_ptr = &juan;
    
    printf("# of resistors is:  %d\n", juan_ptr -> resistors);
    printf("# of capacitors is: %d\n", juan_ptr -> capacitors);
    printf("# of leds is :      %d\n", juan_ptr -> leds);

    juan_ptr -> leds = juan_ptr -> leds - 5;
    juan_ptr -> resistors = juan_ptr -> resistors - 4;

    printf("# of resistors is:  %d\n", juan_ptr -> resistors);
    printf("# of capacitors is: %d\n", juan_ptr -> capacitors);
    printf("# of leds is :      %d\n", juan_ptr -> leds);

/* 
(QE4) What are the member values to be displayed by the following code: 
      Complete the code and explain with your own words.
*/

    printMemContent();
    struct inventory* pvar2 = (struct inventory *) &Array_uint8[8];
    printf("# of resistors is:  %d\n", pvar2->resistors);
    printf("# of capacitors is:  %d\n", pvar2->capacitors);
    printf("# of leds is:  %d\n", pvar2->leds);

/* 
(Example) CASE A: Trivial Casting
*/


    uint8_t  b = 10;
    uint8_t  a = (uint8_t) b;
    printf("Value of b is: %#x\n", b);
    printf("Value of a is: %#x\n", a);


/* 
(Example) CASE B: Integer widening
*/
    int16_t temp16;
    int32_t temp32;

    int8_t i = 0x37;
    temp16 = (int16_t) i;	
    temp32 = (int32_t) i;	
    printf("Value of temp16 is: %#x\n", temp16);
    printf("Value of temp32 is: %#x\n", temp32);

    int8_t  j = 0xc3 ;
    temp16 = (int16_t) j;	
    temp32 = (int32_t) j;	
    printf("Value of temp16 is: %#x\n", temp16);
    printf("Value of temp32 is: %#x\n", temp32);

    uint8_t k = 0x37;
    temp16 = (int16_t) k;
    temp32 = (int32_t) k;		
    printf("Value of temp16 is: %#x\n", temp16);
    printf("Value of temp32 is: %#x\n", temp32);
/* 
(Example) CASE C: Casting integers to a smaller type
*/
    int32_t ic = 0x0cf34bf1;
    //int16_t temp16;
    int8_t temp8;
    uint8_t tempu8;
    temp16 =(int16_t) ic;
    temp8 =(int8_t) ic;			
    tempu8 = (uint8_t) ic;		
    printf("Value of temp16 is: %#x\n", temp16);
    printf("Value of temp8  is: %#x\n", temp8);
    printf("Value of tempu8 is: %#x\n", tempu8);

/* 
(Example) CASE D: Casting integer signed to unsigned
*/
    uint32_t tempu32;
	int32_t id = 0xfffffca9 ;
	tempu32 = (uint32_t) id;	
    printf("Value of id is: %d, tempu32 is: hex %#x  dec %ud\n", id, tempu32, tempu32);			      


/* 
(Example) CASE E: Casting integer signed to unsigned and widening
*/

	int16_t  ie = 0xff55; 		/*	-171 */ 
	tempu32 =(uint32_t) ie; 
    printf("Value of id is: %d, tempu32 is: hex %#x  dec %ud\n", ie, tempu32, tempu32);	



/* 
(QE5) Two steps are performed by the cast operation, which of these pairs of steps correspond
to the code example illustrated below. Justify your answer.

a) 
1. Add bits by doing sign extension if the variable being casted has a sign ("signed")
2. The value is considered an unsigned value

b) 
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered a signed value

c) 
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered an unsigned value

*/

int8_t num = 0x90;
uint32_t num1 = (uint32_t) num;
printf("\nnum1 = %08x", num1);


/* 
(QE6) Two steps are performed by the cast operation, which of these pairs of steps correspond
to the code example illustrated below. Justify your answer.

a) 
1. Add bits by doing sign extension if the variable being casted has a sign ("signed")
2. The value is considered an unsigned value

b) 
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered a signed value

c) 
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered an unsigned value
*/


uint8_t num2 = 0x90;
uint32_t num3 = (uint32_t) num2;
printf("\nnum3 = %08x", num3);


/* 
(QE7) Two steps are performed by the cast operation, which of these pairs of steps correspond to the code example illustrated below. Justify your answer.

a) 
1. Add bits by doing sign extension if the variable being casted has a sign ("signed")
2. The value is considered an unsigned value

b) 
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered a signed value

c)
1. Add bits by filling with zeros if the variable being casted has no sign ("unsigned")
2. The value is considered an unsigned value
*/


uint8_t num4 = 0x90;
int32_t num5 = (int32_t) num4;
printf("\nnum5 = %08x", num5);



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

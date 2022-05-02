#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define BITPOS0 (1 << 0)      /*0x01L*/
#define BITPOS1 (1 << 1)      /*0x02L*/
#define BITPOS2 (1 << 2)      /*0x04L*/
#define BITPOS3 (1 << 3)      /*0x08L*/
#define BITPOS4 (1 << 4)      /*0x10L*/
#define BITPOS5 (1 << 5)      /*0x20L*/
#define BITPOS6 (1 << 6)      /*0x40L*/
#define BITPOS7 (1 << 7)      /*0x80L*/

void PrintToBinary8(uint8_t);
void PrintToBinary16(uint16_t);
void PrintToBinary32(uint32_t);

int main() {
    uint32_t i;
    uint8_t x_reg;

    /* Boolean and bit wise operations */
    /* Class example */
    uint8_t a = 5 && (!3) || 6;
    uint8_t b = 5 & (~3) | 6;


    printf ("The a value is: %x ", a);
    PrintToBinary8(a);
    printf ("The a value is: %x ", b);
    PrintToBinary8(b);


    /* QE1  Capture your code to very your hand written procedure*/
    
    
    /* Bit manipulation 
       This code demonstrates class examples for set, clear and toggle bit
       This code section can be modified for QE2 and QE3*/

    /*Operation  - set bit*/
       
    x_reg = 0x92;
    printf ("x_reg value before set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);

    /* New x_reg value here */

    x_reg = x_reg | (BITPOS5) | (BITPOS3);

    printf ("x_reg value after  set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);  

    /*Operation  - clear bit*/

    x_reg = 0x92;
    printf ("x_reg value before clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg);

    /* New x_reg value here */

    x_reg = (x_reg & ~(BITPOS7)) & ~(BITPOS1);

    printf ("x_reg value after  clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg); 

    /*Operation  - toggle bit*/

    x_reg = 0x92;
    printf ("x_reg value before toggle operation is: %x ", x_reg);
    PrintToBinary8(x_reg);

    /* New x_reg value here */

    x_reg = (x_reg ^ (1 << 4)) ^ (1);

    printf ("x_reg value after  toggle operation is: %x ", x_reg);
    PrintToBinary8(x_reg); 

    /* Bit manipulation 
       This code demonstrates class examples for extract and insert bits
       This code section can be used as reference or modified for QE4
    */

    uint16_t time = 0x9285;     /* hour: 5, minutes:6, seconds: 5 */
    uint16_t minutes = 0;

    /* extracting minutes */
    printf ("Current time is: %x \n", time);
    /* code here */

    uint16_t minutes_temp = time;

    for(int i = 0; i < 6; i++)
      minutes_temp >>= 1;
    
    int my_minutes[6];

    for(int i = 0; i < 6; i++){
      if(minutes_temp % 2){
        my_minutes[i] = 1;
      }else {
        my_minutes[i] = 0;
      }
      minutes_temp >>= 1;
    }

    for(int i = 0; i < 6; i++)
      printf("%d\n",my_minutes[i]);

    for(int i = 5, power = 0; i >= 0; i--, power++){
        int curr = my_minutes[i] * pow(2,power);
        printf("%d\n",curr);
        minutes += curr;
    }

    printf ("Minutes are (Hexadecimal):     %x \n", minutes);
    printf ("Minutes are (Decimal):     %d \n", minutes);

    // Demo

    uint16_t time_for_hours = time;

    uint16_t hours_demo = (time_for_hours) >>= 11;

    printf("These are the hours: %d",hours_demo);


    /* inserting new time */
    printf ("Current time is: %x \n", time);
    /* code here */

    time = ((time ^ (1 << 15)) ^ (1 << 14)) ^ (1 << 11); 

    printf ("New time is:     %x \n", time);
   /* code here */
    printf ("New minutes are: %x \n", minutes);

    int val = 8 && (!10) || 14;
    int newVal = 8 & (~10) | 14;

    printf("%d %d",val,newVal);




/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

void PrintToBinary16(uint16_t num) {
  for(int i=15;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

void PrintToBinary32(uint32_t num) {
  for(int i=31;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}
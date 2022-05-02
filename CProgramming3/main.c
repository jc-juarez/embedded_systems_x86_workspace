// Modified by Juan Carlos Juárez

#include <stdio.h>
#include <stdint.h>

void PrintToBinary(uint32_t, uint32_t);

struct porta1 {
    uint16_t reg;
};

struct qe2 {
    uint8_t StatusRegister;
    uint16_t ControlRegister;
    uint32_t DataRegister;
};

//struct porta2{

union porta3 {
    uint16_t reg;
    struct {
        uint16_t f1 :1,
             f2 :3,
             f3 :4,
             f4 :3,
             f5 :2,
             f6 :2,
             f7 :1;   
    };
};

// Struct for Real Time Clock

struct rtc {
    uint16_t seconds : 5,
             minutes : 6,
             hours : 5;
};

int main() {

    /* Using structure */
    struct porta1 mporta;

   /* Code to Clear all 16-bit port */
    mporta.reg =  mporta.reg & 0x0000;

    printf("porta1- hex: %x \t\tbin: ", mporta.reg);
    PrintToBinary(mporta.reg, 16);
    printf("\n");

    /* Code to Set all 16-bit port */
    mporta.reg =  mporta.reg | 0xFFFF;

    printf("porta1- hex: %x \tbin: ", mporta.reg);
    PrintToBinary(mporta.reg, 16);      
    printf("\n");

    /* Code to Set Initial Value */
    mporta.reg =  mporta.reg & (0x98F1);

    printf("porta1- hex: %x \tbin: ", mporta.reg);
    PrintToBinary(mporta.reg, 16);      
    printf("\n");

    /* QE2 */

    struct qe2 qe2_instance = {20, 30, 40};

    uint32_t temp = qe2_instance.DataRegister;

    printf("\nTemp variable is: %d\n", temp);

    printf("Status Register: %d, Control Register: %d, Data Register: %d\n", qe2_instance.StatusRegister, qe2_instance.ControlRegister, qe2_instance.DataRegister);

    qe2_instance.StatusRegister = qe2_instance.StatusRegister & 0x00;

    printf("Status Register: %d, Control Register: %d, Data Register: %d\n", qe2_instance.StatusRegister, qe2_instance.ControlRegister, qe2_instance.DataRegister);

    printf("The size of the QE2 Struct is: %ld\n", sizeof(qe2_instance));

    /* Using unions*/

    union porta3 uporta;
    
    /* Code to clear everything */
    uporta.reg = 0x0000;

    printf("\nporta3- hex: %x \t\tbin: ", uporta.reg);
    PrintToBinary(uporta.reg, 16);
    printf("\n");

    /* Code to Turn leds at f3 on */
    uporta.f3 = 0xF;

    /* Code to Turn leds at f5 on */
    uporta.f5 = 0x3;

    /* Code to Turn leds at f1 and f7 on*/
    uporta.f7 = 0x1;
    uporta.f1 = 0x1;

    printf("porta3- hex: %x \tbin: ", uporta.reg);
    PrintToBinary(uporta.reg, 16);

    /* QE5 */

    struct rtc my_clock;

    my_clock.seconds = 5; // over 2
    my_clock.minutes = 20;
    my_clock.hours = 18;

    printf("\n\nThe RTC value is: ");
    PrintToBinary(my_clock.hours, 5);
    PrintToBinary(my_clock.minutes, 6);
    PrintToBinary(my_clock.seconds, 5);
    printf("\n");

    printf("\nThe Minutes are: ");
    PrintToBinary(my_clock.minutes, 6);

    my_clock.hours = 0x0A;

    printf("\n\nThe new Hour is: ");
    PrintToBinary(my_clock.hours, 5);

    printf("\n");
    printf("\nworks!\n");

/* End of main program */
    return(0);
}

void PrintToBinary(uint32_t val, uint32_t n) {
  for(int i=(n-1);i>=0;i--){
    if (val & (1<<i))
        printf("1");
    else
        printf("0");
  }  
}
#include <stdio.h>
#include <stdint.h>

union qe4union {	
  uint32_t dd ;	
  uint16_t dw[2] ;	
  uint8_t  db[4] ;	
} ;	
int main(){
union qe4union var;
var.dd = 0xAABBCCDD;
printf("\n %x", sizeof(var));  
printf("\n %x",var.dd );        
printf("\n %x",var.dw[1]);    
printf("\n %x",var.db[1]);        
return(0);
}

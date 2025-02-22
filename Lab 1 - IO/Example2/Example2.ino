#include<avr/io.h>
int main(){
  DDRB = 0xFC;
  DDRC = 0x03;
  PORTC = 0x00;
  while(1){
    if(PINB & 0x1){
      PORTC |= (1 << PC0);
    } else {
      PORTC &= ~(1 << PC0);
    }
    if(PINB & 0x2){
      PORTC |= (1 << PC1);
    } else{
      PORTC &= ~(1 << PC1);
    }
  }
}
#include<avr/io.h>
#include<util/delay.h>

int main(){
  DDRD = 0x40;
  PORTD = 0x40;
  while(1){
    _delay_ms(1000);
    PORTD ^= (1 << PD6);
  }
}
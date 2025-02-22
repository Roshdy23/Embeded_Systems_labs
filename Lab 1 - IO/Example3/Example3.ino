#include<avr/io.h>
#include<util/delay.h>

int main(){
  DDRB = 0xFE;
  PORTB = 0x01;
  DDRC = 0x01;
  PORTC = 0x01;
  bool initialized = false;
  bool changed = false;
  while(1){
    if((PINB & 0x01)){
      if(!changed && initialized){
        _delay_ms(30);
        if((PINB & 0x01)){
          PORTC ^= ( 1 << PC0 );
          changed = true;
        }
      }
    } else {
      changed = false;
      initialized = true;
    }
  }
}
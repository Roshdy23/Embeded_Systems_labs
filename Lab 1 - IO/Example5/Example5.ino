#include<avr/io.h>
#include<util/delay.h>

u8 BCD_7seg(u8 num){
  if(num == 0x1) {
    return 0b0000110;
  } else if(num == 0x2) {
    return 0b1011011;
  } else if(num == 0x3){
    return 0b1001111;
  } else if(num == 0x4){
    return 0b1100110;
  } else if(num == 0x5){
    return 0b1101101;
  } else if(num == 0x6){
    return 0b1111101;
  } else if(num == 0x7){
    return 0b0000111;
  } else if(num == 0x8){
    return 0b1111111;
  } else if(num == 0x9){
    return 0b1101111;
  } else {
    return 0b0111111;
  }
}

int main(){
  DDRC = 0xF0;
  DDRD = 0x7F;
  u8 num = 0;
  bool initializedA = false;
  bool initializedB = false;
  bool changedA = false;
  bool changedB = false;
  PORTD = BCD_7seg(num);
  while(1){
    if ( !(PINC & 0x01)){
      if(!changedA && initializedA){
        _delay_ms(30);
        if(!(PINC & 0x01)){
          num = (num+1 > 9)?9:num+1;
          PORTD = BCD_7seg(num);
          changedA = true;
        }
      }
    } else {
      initializedA = true;
      changedA = false;
    }
    if ( !(PINC & 0x02)){
      if(!changedB && initializedB){
        _delay_ms(30);
        if(!(PINC & 0x02)){
          num = (num == 0)?0:num-1;
          PORTD = BCD_7seg(num);
          changedB = true;
        }
      }
    } else {
      initializedB = true;
      changedB = false;
    }
  }
}
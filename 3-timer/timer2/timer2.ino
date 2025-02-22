#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint8_t overflows;
volatile uint8_t num;
ISR(TIMER2_OVF_vect) {
  overflows++;
}
uint8_t BCD_7seg(uint8_t num){
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

void timer2_init(){
// set up timer with prescaler = 256
TCCR2B |= (1 << CS02);
// initialize counter
TCNT2 = 0;
// enable overflow interrupt
TIMSK2 |= (1 << TOIE0);
// enable global interrupts
sei();
// initialize overflow counter variable
overflows = 0;
num=0;
}

void setup() {
  // put your setup code here, to run once:
   timer2_init();
 
 DDRD =  0xFF;
  PORTD = 0;
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(overflows>=244) {
      if(TCNT2 >= 36 ) {
        overflows=0;
        TCNT2 =0;
        num+=1;
        if(num >= 10)
        num =0;
        PORTD =BCD_7seg(num);
      }
  }

}

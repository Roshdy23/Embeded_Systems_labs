
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
ISR(INT1_vect) {
  for(int i= 0; i < 5; i++) {
    PORTC = 0X00;
    _delay_ms(500);
    PORTC |= (1 << 3) | (1 << 1) | (1 << 2);
    _delay_ms(500);
  
  }
}


ISR (INT0_vect) {
  
  PORTC = ( PORTC ^ (1 << PC0));
}

void INT_init(void) {

  SREG &= ~(1<<7);
  DDRD &= ~(1<<PD3);
  DDRD &= ~ (1 << PD2);
  EIMSK |= (1<<INT1);
  EIMSK |= (1 << INT0);
  EICRA |= (1<<ISC11) | (1<<ISC10);
  EICRA |= ( 1<< ISC00);
  EICRA |= (1 << ISC01);
  SREG |= (1 << 7);
}
void setup() {
  // put your setup code here, to run once:
   INT_init();
  DDRC |= (1 << PC3) | (1 << PC1) | (1 << PC2) | (1 << PC0);
  PORTC =0x00;
 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  PORTC |= (1<< 3);
  PORTC &= ~(1<< 1);
   PORTC &= ~(1<< 2);
  _delay_ms(500);
PORTC |= (1<< 1);
  PORTC &= ~(1<< 3);
   PORTC &= ~(1<< 2);
  _delay_ms(500);
 PORTC |= (1<< 2);
  PORTC &= ~(1<< 1);
   PORTC &= ~(1<< 3);
  _delay_ms(500);
}

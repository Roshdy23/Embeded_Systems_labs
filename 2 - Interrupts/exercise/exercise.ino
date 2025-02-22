
#include <avr/io.h>
#include <avr/interrupt.h>


ISR (INT0_vect) {
  
  PORTC = ( PORTC ^ (1 << PC0));
}

void INT_init (void) {
  
  SREG &= ~ ( 1 << 7);
  
  DDRD &= ~ (1 << PD2);

  EIMSK |= (1 << INT0);

  EICRA |= ( 1<< ISC00);
  EICRA |= (1 << ISC01);

   SREG |=  ( 1 << 7);
}

void setup() {
  
  INT_init();
  
  DDRC = 0x01;
  PORTC &= ~(1<<PC0);  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}


#include <avr/io.h>
#include <avr/interrupt.h>
ISR (TIMER1_COMPA_vect)
{
// toggle led here
PORTC ^=(1<<0);
}
void timer1_init() {
  TCCR1B |= (1 << WGM12)|(1 << CS02)|(1 << CS00);
  TCNT1 = 0;
  OCR1A = 7812;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void setup() {
  // put your setup code here, to run once:
  timer1_init();
  DDRC |= (1<<0);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

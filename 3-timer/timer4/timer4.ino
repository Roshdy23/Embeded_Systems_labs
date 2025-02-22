#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER2_COMPA_vect) {
  // Toggle PB3 on compare match
  PORTB ^= (1 << PB3);
}

void timer2_init(){

// ctc
  TCCR2B = (1<<WGM01);
//1024
TCCR2B |= (1 << CS22)|(1 << CS21) | (1 << CS20);
// enable toogle interrupt
TCCR2A |= ( 1 << COM2A0);
// start your cnt =0
TCNT2 = 0;
// the compare value
OCR2A = 250;
// enable listeniing to compare interrupt
TIMSK2 |= (1 << OCIE2A);
// enabl
sei();
}

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << PB3);
  timer2_init();
}

void loop() {
  // put your main code here, to run repeatedly:

}

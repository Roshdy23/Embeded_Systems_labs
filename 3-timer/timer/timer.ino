
#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint8_t tot_overflow = 0;

ISR(TIMER2_OVF_vect)
{
tot_overflow++;
}

void timer2_init(){

TCCR2B |= (1 << CS02) | (1 << CS00);

TCNT2 = 0;

TIMSK2 |= (1 << TOIE2);

sei();

tot_overflow = 0; 
}
void setup() {
  // put your setup code here, to run once:
DDRC |= (1 << PC0);
timer2_init();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(tot_overflow >=30) {
    if(TCNT2 >= 133) {
      PORTC ^= (1 << 0); 
      TCNT2 = 0; 
      tot_overflow = 0;
    }
  }


}

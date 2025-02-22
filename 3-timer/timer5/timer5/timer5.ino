#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t period = 0;
volatile uint16_t firstTime = 0;
volatile uint16_t secondTime =0;
volatile uint8_t first =1;   
ISR(TIMER2_COMPA_vect) {
  // Toggle PB3 on compare match
  PORTB ^= (1 << PB3);
}


ISR(TIMER1_CAPT_vect) {
  if(first) {
    firstTime = ICR1;
    first = 0;
  } else {
    secondTime = ICR1;
    period = secondTime - firstTime;
    first =1;
      TCNT1 = 0;
  }
  
  TIFR1 = (1 << ICF1); 
}
void timer1_init() {
  TCCR1A = 0;
  TCCR1B = (1 << CS10) | (1 << ICES1);
  TIMSK1 = (1 << ICIE1);
  TCNT1 = 0;
  sei();
}

void timer2_init(){

// ctc
  TCCR2A = (1<<WGM21);
//1024
TCCR2B = (1 << CS22)|(1 << CS21) | (1 << CS20);
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
  DDRB = (1 << PB3);
  DDRB &= ~(1 << PB0);
  timer1_init();
  timer2_init();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(period > 0){
    Serial.print("period : ");
    Serial.println(period);
    period=0;
 
  }
}

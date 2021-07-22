
int a=0,b=0;
void setup() {
  Serial.begin(9600);
  cli();                      //stop interrupts for till we make the settings 
  //Timer 1 (interrupt each 50ms)
  TCCR1A = 0;                 // Reset entire TCCR1A to 0 
  TCCR1B = 0;                 // Reset entire TCCR1B to 0
  TCCR1B |= B00000100;        //Set CS12 to 1 so we get prescalar 256  
  TIMSK1 |= B00000110;        //Set OCIE1A and OCIE1B to 1 -> compare match A and B
  sei();                      //Enable back the interrupts                    
}

void loop() {
 Serial.print(a);
 Serial.print("\t");
 Serial.println(b);
 delay(500);
 
}



ISR(TIMER1_COMPA_vect){
 b +=2;
}

ISR(TIMER1_COMPB_vect){
  a++;
}

int led=20;
int ban=0;
void setup(){
  pinMode(led, OUTPUT);
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS11);
  TCCR1B |= (1 << CS10); 
  OCR1AH = 0x7A; OCR1AL = 0X11;
  TIMSK1 |= (1 << OCIE1A);
  sei();
 }
ISR(TIMER1_COMPA_vect){
  if(ban==1){
    digitalWrite(led,LOW);
    ban=0;   
  }
  else{
    digitalWrite(led,HIGH);   
    ban=1;
  }
}
void loop()
{
}

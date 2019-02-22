int led=20;
int ban=0;
void setup(){
  pinMode(led, OUTPUT);
  cli();
  TCCR1B = 0; 
  TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TCNT1 = 34286;
  TIMSK1 |= (1 << TOIE1);
  sei();
 }
ISR(TIMER1_OVF_vect){
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

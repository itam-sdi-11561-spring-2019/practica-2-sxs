int ledV=20;
int ledR=21;
int ledA=22;
int seg=0;
int ban=1;
void setup(){
  pinMode(ledV, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10); //Retraso de 1 segundo con pre 1024
  OCR1AH = 0B00111101; OCR1AL = 00001000;
  TIMSK1 |= (1 << OCIE1A);
  sei();
 }
ISR(TIMER1_COMPA_vect){
  switch(ban){
    case 1:
    digitalWrite(ledV,HIGH);
    seg++;
    if(seg<=14){
      if(seg==12){
        digitalWrite(ledA,HIGH);
      }
    }
    else{
      seg=0;
      digitalWrite(ledA,LOW);
      digitalWrite(ledV,LOW);
      digitalWrite(ledR,HIGH);
      ban=2;
    }
    break;
    case 2:
    seg++;
    if(seg==10){
      seg=0;
      digitalWrite(ledR,LOW);
      digitalWrite(ledV,HIGH);
      ban=1;
    }
    break;
  }
 
}
void loop()
{
}

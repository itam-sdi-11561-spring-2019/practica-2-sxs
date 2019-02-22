int led=34;
int btn=A9;
int cont=0;
int btns=0;
int band=0;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(btn, INPUT);
  
  cli();
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei();
}

void loop(){
  btns=analogRead(btn);
  
  if(btns <32 ){
    if(band==0){
      band=1;
      digitalWrite(led,HIGH);
      cont++;
    }
  }
  else{
    if(band==1){
        band=0;
        digitalWrite(led,LOW);
    }
  }
  Serial.println(cont);
  delay(250);
}


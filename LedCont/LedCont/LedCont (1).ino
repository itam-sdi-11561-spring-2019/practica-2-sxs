int led=34;
int btn=30;
int cont=0;
int btns=0;
int band=0;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(btn, INPUT);
}

void loop(){
  btns=digitalRead(btn);
  
  if(btns == LOW){
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
}


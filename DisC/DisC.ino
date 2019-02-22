

int a=10;
int b= 20; 
int c= 30;
int res=0;
void setup(){
  Serial.begin(9600);
}

void loop(){
  res=b*b-4*a*c;
  Serial.println(res);
  delay(500);
}

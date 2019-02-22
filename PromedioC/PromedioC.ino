int n=4;
int numbers []= {2,70,5,3};
int sum=0;
int res=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  for (unsigned int a = 0; a < n; a = a + 1){
    sum= sum + numbers [a];
  }
  res=sum/n;
  Serial.println(res);
  while(true){}
}

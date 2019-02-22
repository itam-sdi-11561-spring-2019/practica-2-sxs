 

int res1=0;
int res2=0;
void setup(){
  Serial.begin(9600);
}

void loop(){
  asm volatile(
  "LDI r22, 10 \n" //a
  "LDI r23, 20 \n" //b
  "MUL r23, r23 \n" //bb
  "MOV r24, r0 \n" // R24 bb
  "MOV r25, r1 \n" // R25 bb 
  "LDI r26, 30 \n" // c
  "LDI r27, 4 \n"
  "MUL r22, r27  \n" // 4a
  "MOV r22, r0 \n"
  "MOV r23, r1 \n"
  "MUL r22, r26 \n" // 4ac  en R0 y R1
  "SUB r24, r0 \n" //
  "SBC r25, r1 \n"
  "movw %0, R24 \n"
  : "=r" (res1)
  );
 if (res1==-800){
   Serial.println("-800");
 }
 delay(1000);
}

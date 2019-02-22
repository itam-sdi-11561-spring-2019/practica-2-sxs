
void setup(){
  Serial.begin(9600);
  
}

void loop (){
  int prom=0;
  asm volatile(
  "LDI r16, 70 \n\t"
  "LDI r17, 5  \n\t"
  "LDI r18, 10 \n\t"
  "LDI r19, 15 \n\t"
  "LDI r20, 5  \n\t"
  "ADD r16, r17 \n\t"
  "ADD r16, r18 \n\t"
  "ADD r16, r19 \n\t"
  "ADD r16, r20 \n\t"
  "LDI r17, 5 \n\t"
  "LDI r18, 0 \n\t"
  "lop:\n\t"
  "INC r18 \n\t"
  "SUB r16,r17 \n\t"
  "BRNE lop \n\t"
  "mov r10, r18 \n\t"
  "mov %0, r10 \n\t"
  : "=r" (prom)
  );
  Serial.println(prom);
  delay(1000);
}

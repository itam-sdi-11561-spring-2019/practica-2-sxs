int led =34;

void setup(){
  Serial.begin(9600);
  DDRC=DDRC | B00001000;
}

void loop(){
  asm volatile(
  "cbi %0, %1 \n\t" 
  "sbis %2, %3 \n\t"
  "sbi %0, %1 \n\t"
  : : "I" (_SFR_IO_ADDR(PORTC)), "I" (PORTC3),"I" (_SFR_IO_ADDR(PINC)), "I" (PINC7):
  );
}

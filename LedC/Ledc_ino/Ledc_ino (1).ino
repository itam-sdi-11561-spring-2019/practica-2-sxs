int led = 34;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 digitalWrite(led, HIGH);
 delay(250);
 digitalWrite(led, LOW);
 delay(250);
}

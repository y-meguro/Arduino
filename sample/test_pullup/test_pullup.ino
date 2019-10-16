void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(8));
  delay(1000);
}

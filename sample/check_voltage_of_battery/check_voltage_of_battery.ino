void setup() {
  Serial.begin(9600);
}

void loop() {
  // float vt = (float) analogRead(0) / 1023.0 * 5.0;
  float vt = (flosat) map (analogRead(0), 0, 1023, 0, 500) / 100.0;
  Serial.println(vt);
  delay(1000);
}

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("*** Arduino test ***");
  Serial.println("+++ Uno R3 test +++");
  delay(300);
}

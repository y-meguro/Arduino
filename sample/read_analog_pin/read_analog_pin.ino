int analogPin = 0;     //ポテンショメーターの真ん中の端子をアナログピンの3番に接続
int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  Serial.println(val* 5.0 / 1023.0);
  delay(1000);
}

int dn; // LED点滅待機時間

void setup() {
  Serial.begin(115200);
  Serial.print(" delay msec=");
  dn = readKeyboard().toInt();
  Serial.println(dn);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(dn);
  digitalWrite(13, LOW);
  delay(dn);
}

String readKeyboard() {
  char str[100];
  char ch;
  int i = 0;
  boolean sw = true;
  unsigned long tms;

  while(sw) {
    ch = Serial.read();
    if (ch >= 0 && ch <= 127) {
      tms = millis();
      str[i] = ch;
      i++;
    } else if ((millis() - tms > 300) && (i > 0)) {
      str[i] = 0;
      sw = false;
    }
  }
  return String(str);
}

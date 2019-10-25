unsigned char rom[] = {
  // サンプルプログラム1: LEDちかちか
  B10110011, // OUT 0011
  B10110110, // OUT 0110
  B10111100, // OUT 1100
  B10111000, // OUT 1000
  B10111000, // OUT 1000
  B10111100, // OUT 1100
  B10110110, // OUT 0110
  B10110011, // OUT 0011
  B10110001, // OUT 0001
  B11110000, // JMP 0000
};

void setup() {
  Serial.begin(9600);
  DDRB = DDRB | B00001111;
  DDRC = DDRC | B00001111;
}

void loop() {
  // アドレス入力 D5 D4 D3 D2 番ピン（右が最下位ビット）
  // データ出力   D11 D10 D9 D8 A3 A2 A1 A0 番ピン（右が最下位ビット）
  unsigned char addr = (PIND & B00111100)>>2;
  Serial.println(addr);

  PORTC = (PORTC & B11110000) | (rom[addr] & B00001111);
  PORTB = (PORTB & B11110000) | ((rom[addr] & B11110000)>>4);
}

unsigned char rom[] = {
  // サンプルプログラム2: ラーメンタイマー
  B10110111, // OUT 0111
  B00000001, // ADD A,0001
  B11100001, // JNC 0001
  B00000001, // ADD A,0001
  B11100011, // JNC 0011
  B10110110, // OUT 0110
  B00000001, // ADD A,0001
  B11100110, // JNC 0110
  B00000001, // ADD A,0001
  B11101000, // JNC 1000
  B10110000, // OUT 0000
  B10110100, // OUT 0100
  B00000001, // ADD A,0001
  B11101010, // JNC 1010
  B10111000, // OUT 1000
  B11111111, // JMP 1111
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

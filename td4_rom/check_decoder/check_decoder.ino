unsigned char rom[] = {
  // 命令デコーダのチェック用
  B00000000, // ADD A,Im
  B00010000, // MOV A,B
  B00100000, // IN A
  B00110000, // MOV A,Im
  B01000000, // MOV B,A
  B01010000, // ADD B,Im
  B01100000, // IN B
  B01110000, // MOV B,Im
  B10010000, // OUT B
  B10110000, // OUT Im
  B11100000, // JNC(C=0 or C=1)
  B11110000, // JMP
};

void setup() {
  DDRB = DDRB | B00001111;
  DDRC = DDRC | B00001111;
}

void loop() {
  // アドレス入力 D5 D4 D3 D2 番ピン（右が最下位ビット）
  // データ出力   D11 D10 D9 D8 A3 A2 A1 A0 番ピン（右が最下位ビット）
  unsigned char addr = (PIND & B00111100)>>2;

  PORTC = (PORTC & B11110000) | (rom[addr] & B00001111);
  PORTB = (PORTB & B11110000) | ((rom[addr] & B11110000)>>4);
}

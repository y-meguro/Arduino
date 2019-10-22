unsigned char rom[] = {
  // Aレジスタのスライドアニメーションを
  // Bレジスタが1クロック遅れで追いかけるプログラム
  B00110001, // MOV A,0001
  B01000000, // MOV B,A
  B00110011, // MOV A,0011
  B01000000, // MOV B,A
  B00110111, // MOV A,0111
  B01000000, // MOV B,A
  B00111111, // MOV A,1111
  B01000000, // MOV B,A
  B00111110, // MOV A,1110
  B01000000, // MOV B,A
  B00111100, // MOV A,1100
  B01000000, // MOV B,A
  B00111000, // MOV A,1000
  B01000000, // MOV B,A
  B00110000, // MOV A,0000
  B01000000, // MOV B,A
};

void setup() {
  DDRB = DDRB | B00001111;
  DDRC = DDRC | B00001111;
}

void loop() {
  // アドレス入力 D5 D4 D3 D2 番ピン（右が最下位ビット）
  // データ出力   D11 D10 D9 D8 A3 A2 A1 A0 番ピン（右が最下位ビット）
  unsigned char addr = (PIND & B00111100)>>2;
  // unsigned char addr = B00000111;

  PORTC = (PORTC & B11110000) | (rom[addr] & B00001111);
  PORTB = (PORTB & B11110000) | ((rom[addr] & B11110000)>>4);
}

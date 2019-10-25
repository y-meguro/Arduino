unsigned char rom[] = {
  // JNCのチェック用
  // 最初の入力ポートは1111
  B00100000, // IN A: Aレジスタが1111であることを確認
  B00000001, // ADD A,Im: Aレジスタが0000であることを確認
  B11100000, // JNC(C=1): シリアルモニターでジャンプしていないことを確認
  
  // 入力ポートを0001にする
  B00100000, // IN A: Aレジスタが0001であることを確認
  B00000001, // ADD A,Im: Aレジスタが0010であることを確認
  B11100000, // JNC(C=0): シリアルモニターで最初の命令に戻ったことを確認
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

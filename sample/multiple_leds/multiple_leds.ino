// LEDをつなぐピンを定義
int led_pins[] = {8, 9, 10, 11, A0, A1, A2, A3};
int FADE_TIME = 2;
 
// 初期化
void setup(){
  int i;
  
  // LEDのピンを出力に
  for (i=0; i<8; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  int i,j;
 
  // LEDを暗から明へフェード
  for (j=0; j<8; j++) {
    for (i=0; i<256; i++) {
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }
 
  // LEDを明から暗へフェード
  for (j=0; j<8; j++) {
    for (i=255; i>-1; i--) {
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }
}

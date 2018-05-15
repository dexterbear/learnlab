#include <Adafruit_NeoPixel.h> //neo rgb 라이브러리

#define PIN 6 //아날로그 출력
#define LED_number 2 //rgb led 개수

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
//라이브러리에 있는 함수를 이용해 rgb led 설정, Adafruit_NeoPixel(led개수, 아날로그 출력핀 위치, 센서종류)

void setup() {
  leds.begin(); //라이브러리 시작
  leds.show();  //내가 led를 키기위한 함수, 지금은 전부 꺼진 상대
 
}

void loop() {
  for(int x=0; x<LED_number; x++){
    leds.setPixelColor(x,255,255,0); //연결한 모든 led를 노란색으로 출력
  }                                  //leds.setPixelColor(led개수,r값,g값,b값)
  leds.show(); //led를 킨다.

}
 
  

  


  


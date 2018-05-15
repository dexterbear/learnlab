int buzzer = 5;

const int C = 1046;   //부저에서 나오는 소리의 주파수
const int D = 1175;   //const는 변하지 않는값
const int E = 1319;
const int F = 1397;
const int G = 1568;
const int A = 1760;
const int B = 1976;
const int C1 = 2093;
const int D1 = 2249;

void setup() {
  
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
 
}

void loop() {
  tone(buzzer,C);   //tone(디지털출력번호,주파수) ON
  delay(100);
  tone(buzzer,D);
  delay(100);
  tone(buzzer,E);
  delay(100);
  tone(buzzer,F);
  delay(100);
  tone(buzzer,G);
  delay(100);
  tone(buzzer,A);
  delay(100);
  tone(buzzer,B);
  delay(100);
  tone(buzzer,C1);
  delay(100);
  tone(buzzer,D1);
  delay(100);

  noTone(buzzer);  //noTone(디지털출력번호) 소리 OFF

  delay(300);
  
}
  


  


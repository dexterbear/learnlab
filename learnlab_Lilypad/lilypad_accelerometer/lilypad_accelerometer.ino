const int x_pin = A1; //x,y,z 축에 해당되는 가속도계센서
const int y_pin = A2;
const int z_pin = A3;

float x_g;  //계산된 x,y,z축의 가속도값
float y_g;
float z_g;
int smaple_delay = 500;


void setup() {
  
  Serial.begin(9600);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(z_pin, INPUT);
  
}

void loop() {
  int x = analogRead(x_pin);
  delay(1);  //가속도값을 읽기위한 멈춤시간
  int y = analogRead(y_pin);
  delay(1);
  int z = analogRead(z_pin);
  
  float zero_G = 512; //움직임이 없을때 초기 중력값

  float scale = 102.3; //1G가 변할때 센서값을 보정하기 위한값

  x_g = ((float)x - zero_G)/scale;
  y_g = ((float)y - zero_G)/scale;
  z_g = ((float)z - zero_G)/scale;

  delay(sample_delay); //다음 측정 이전의 쉬는 타임
}
  


  


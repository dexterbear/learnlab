int sensor = A3; //아날로그 입력
int light; //빛의 세기값을 받는 곳

void setup()
{
  Serial.begin(9600);//시리얼 모니터링 설정 On
 
  pinMode(sensor,INPUT);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH); //항상 값을 받기위한 설정
  pinMode(3,OUTPUT);
}

void loop()
{
  light = analogRead(sensor); //빛의 세기값을 받는다.

  Serial.print("Light value is:");//시리얼 모니터에 표시
  Serial.println(light);
  delay(10);//약간의 처리시간을 준다

  if(light <500){
    digitalWrite(3,HIGH);
    delay(10);
  }
  else if(light > 500){
    digitalWrite(3,LOW);
    delay(10);
  }
}




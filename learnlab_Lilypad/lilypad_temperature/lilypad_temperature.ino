int temper_sensor = A3;
long temper_read;
float temper_voltage;
float temper_c;
float temper_f;
char c;

void setup() {
  Serial.begin(9600);
  pinMode(temper_sensor,INPUT);
  
  pinMode(A5,OUTPUT);
  digitalWrite(A5,HIGH);

  
}

void loop() {
  temper_read = analogRead(temper_sensor);
  temper_voltage = temper_read * 3.3 / 1023.0;
  temper_c = (temper_voltageage - 0.5)*100; //섭시온도
  temper_f = (temper*9/5)+32; //화씨온도
  Serial.print("temperature_c:");
  Serial.println(temper_c);
  Serial.print("temperature_f:");
  Serial.println(temper_f);
}
  


  


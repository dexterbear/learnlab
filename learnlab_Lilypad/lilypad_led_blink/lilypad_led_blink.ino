int led_1 = 5;
int led_2 = 6;
int led_3 = 7;

void setup() {
  Serial.begin(9600);
  
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
}

void loop() {
  digitalWrite(led_1,HIGH);
  delay(100);
  digitalWrite(led_1,LOW);
  delay(100);
  digitalWrite(led_2,HIGH);
  delay(100);
  digitalWrite(led_2,LOW);
  delay(100);
  digitalWrite(led_3,HIGH);
  delay(100);
  digitalWrite(led_3,LOW);
  delay(200);
}
  


  


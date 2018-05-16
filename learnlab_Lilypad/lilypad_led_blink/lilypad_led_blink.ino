int led_1 = 5;


void setup() {
  Serial.begin(9600);
  
  pinMode(led_1,OUTPUT);

}

void loop() {
  digitalWrite(led_1,HIGH);
  delay(100);
  digitalWrite(led_1,LOW);
  delay(100);
}
  


  


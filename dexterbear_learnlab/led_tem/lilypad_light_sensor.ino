int sen = A3;
int light;

void setup()
{
  Serial.begin(9600);
 
  pinMode(sen, INPUT);
  pinMode(A5,OUTPUT);
  digitalWrite(A5,HIGH);
}

void loop()
{
  light = analogRead(sen);

  Serial.print("Light value is:");
  Serial.println(light);
  delay(100);
}




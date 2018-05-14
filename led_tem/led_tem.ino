int tempin = A3;
int tempread;
float voltage;
float temp;
char c;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  analogWrite(11,0);
  analogWrite(10,255);
  analogWrite(9,255);
  
  digitalWrite(2,1);
}

void loop() {
  tempread = analogRead(tempin);
  voltage = tempread * 4.15 / 1024.0;
  temp = (voltage - 0.5)*100;
  temp = (temp-32)/1.8;
  Serial.println(temp);
  if(temp >= 12.0){
    c = "1";
    }
    else if(temp <=12 and temp >= 11){
      c = "2";
    }
    else;{
      c = "3";
    }
  if(Serial.available()){
    c = Serial.read();
  }
  
  switch(c){
    case'1':
      for (int i=0; i<255; i++){
       analogWrite(11,i);
       analogWrite(10,255-i);
       analogWrite(9,255-i);
       delay(10); 
      }
      c = "";
    break;
    case'2':
      for (int i=0; i<255; i++){
       analogWrite(11,255-i);
       analogWrite(10,i);
       analogWrite(9,255-i);
       delay(10); 
      }
      c = "";
    break;
    case'3':
      for (int i=0; i<255; i++){
       analogWrite(11,255-i);
       analogWrite(10,255-i);
       analogWrite(9,i);
       delay(10); 
      }
      c = "";
    break;
  }
  


}
  


  


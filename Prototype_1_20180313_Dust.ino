#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
#include <LiquidCrystal_I2C.h>
#include <Wire.h>  
int blueTx=2;   //Tx (보내는핀 설정)
int blueRx=3;    //Rx (받는핀 설정)

SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
LiquidCrystal_I2C lcd(0x3F,16,2);
String myString=""; //받는 문자열
String LCD =""; 

int dustPin = A0;
float dustVal = 0;
float dustDensity = 0;
float dustDensityug=0;
float voMeasured = 0;
float calcVoltage = 0;

int count = 0;
int ledPower = 12;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;
float pre_dustDensityug;
float old_dustDensityug;

#define loop_timer 200
#define fan 7
unsigned long timer = 0;


void setup(){
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 
  lcd.begin();
  lcd.backlight();
  pinMode(ledPower,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(fan,OUTPUT);
}

void loop(){
  
  if(millis() - timer >= loop_timer){
    timer = millis();
   
    digitalWrite(ledPower, LOW); // LED
    delayMicroseconds(delayTime);

    dustVal=analogRead(dustPin);
    calcVoltage = dustVal * (5.0 / 1024); 
  
    delayMicroseconds(delayTime2);

    digitalWrite(ledPower, HIGH); //LED off
    delayMicroseconds(offTime);

    pre_dustDensityug = (0.17 * calcVoltage - 0.1)*1000; 

    dustDensityug += pre_dustDensityug;
    count += 1;
  }
  if (count == 20){
    old_dustDensityug = dustDensityug/20;
    Serial.print("Dust Density [ug/m3]: ");
    Serial.println(abs(old_dustDensityug));

    lcd.begin();
    lcd.print("Dust Density");
    lcd.setCursor(0,1);
    lcd.print(abs(old_dustDensityug));
    lcd.setCursor(5,1);
    lcd.print("[ug/m^3]");
    count = 0;
    dustDensityug=0;
    
  }
  while(mySerial.available())
  {
    char myChar = (char)mySerial.read();
    myString  += myChar;
    delay(5);
  }
  if(!myString.equals("")){
    if(myString == "on"){
      digitalWrite(fan,HIGH);
      lcd.begin();
      lcd.print("Fan Operate");
      delay(20);
      myString="";
    }
    if(myString == "off"){
      digitalWrite(fan,LOW);
      lcd.begin();
      lcd.print("ByeBye");
      delay(20);
      myString="";
    }
  
  }
}

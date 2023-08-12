#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float distancecm;
float distanceIN;
long duration;
const float trigpin=12;
const float echopin=13;

void setup() {
  lcd.begin(16,2); //
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);      //clear trigpin
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);    //set trigpin high for 10 ms
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH); //read pulse or soundwaves produced by triger  
  distancecm= duration*0.034/2;   // v=d/t so d=v*t ultrasonic speed =0.034cm
  distanceIN= duration*0.0113/2;     
  Serial.print("Distance in CM: ");
  Serial.println(distancecm);
  Serial.print("Distance in INCHES: ");
  Serial.println(distanceIN);
  
  lcd.setCursor(0, 0);   
  lcd.print("Dist in CM:");
  lcd.print(distancecm);
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("Dist in IN:");
  lcd.print(distanceIN);
  delay(100);

  if(distancecm<=10){
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }


}

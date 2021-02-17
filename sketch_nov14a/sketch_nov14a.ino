#include <Blynk.h>

#include <DS3231.h>

#include <Wire.h>

#include <LiquidCrystal.h>

#include <Servo.h>

//LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//REAL TIME CLOCK
DS3231  rtc(SDA, SCL);

Time  t;

int Hor;

int Min;

int Sec;

//BUZZER
#define buz 11

//SERVO MOTOR
Servo servo1;

int pos1=0;

#define sensorPin 1 // capactitive touch sensor - Arduino Digital pin D1

int ledPin = pin; // Output display LED (on board LED) - Arduino Digital pin D13

boolean currentState = LOW;
boolean lastState = LOW;
boolean RelayState = LOW;

void setup()

{  

  Wire.begin();

  rtc.begin();

  Serial.begin(9600);

  pinMode(buz, OUTPUT);

  lcd.begin(16,2);     

  //lcd.setCursor(0,0);

  //lcd.print("DIYHacking.com");

  //lcd.setCursor(0,1);

  //lcd.print("Arduino Alarm ");

  // The following lines can be uncommented to set the date and time

  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY

  rtc.setTime(15, 0, 0);     // Set the time to 12:00:00 (24hr format)

  rtc.setDate(11, 14, 2019);   // Set the date to January 1st, 2014

  servo1.attach(pin);

  servo1.write(0);

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
  
  delay(2000);

}




void loop()

{

  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;

  lcd.setCursor(0,0);

  lcd.print("Time: ");

  lcd.print(rtc.getTimeStr());

 lcd.setCursor(0,1);

 lcd.print("Date: ");

 lcd.print(rtc.getDateStr());




 if( Hor == 11 &&  (Min == 32 || Min == 33)) //Comparing the current time with the Alarm time

{

Buzzer();

Buzzer();

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Alarm ON");

lcd.setCursor(0,1);

lcd.print("Alarming");

       for(pos1=0  ;pos1<180 ; pos1+=1)
       {
        servo1.write(pos1);
        delay(10);
       }
    
        for(pos1=180 ; pos1>=1  ; pos1-=1)
       {
        servo1.write(pos1);
        delay(10);
       }
Buzzer();

Buzzer();

} //if close

 delay(1000); 

// TOUCH SENSOR
 int senseValue = digitalRead(sensorPin);
  if (senseValue == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
    digitalWrite(buz, LOW);
  }
 // else{
 //   digitalWrite(ledPin,LOW);
 //   Serial.println("not touched"); } 
 
  delay(500);

} //loop close

  lastState = currentState;

void Buzzer()

{

digitalWrite(buz,HIGH);

delay(500);

}

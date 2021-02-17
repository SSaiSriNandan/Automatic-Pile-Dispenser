#define sensorPin 2 // capactitive touch sensor - Arduino Digital pin D1

#include <Servo.h>


int buzzerPin = 13; // Output display LED (on board LED) - Arduino Digital pin D13
int ledPin =12;


//SERVO MOTOR
Servo servo1;
int pos1=0;

void setup() {
  
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin,HIGH);
 digitalWrite(buzzerPin,HIGH);
  servo1.attach(8);
  servo1.write(0);
}
 
void loop() {
  int senseValue = digitalRead(sensorPin);
  if (senseValue == HIGH){
    Serial.println("TOUCHED");
    servo1.write(50);
    digitalWrite(buzzerPin, LOW);
     digitalWrite(ledPin, LOW);
       
  }
  else{
    delay(500);
    Serial.println("not touched");
    servo1.write(pos1);
  } 
   
  delay(70);
  
}

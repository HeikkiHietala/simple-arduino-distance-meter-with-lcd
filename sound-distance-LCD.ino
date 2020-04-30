/*
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig: 11
        Echo: 12
        GND: GND
        
        The display unit connections are configured
        for displays without the I2C backpack. If your display
        has one, the connections are different.
        
        rs: 10
        en: 9
        d2: 4
        d3: 5
        d6: 4
        d7: 5
 */
#include <LiquidCrystal.h>
const int rs = 10, en = 9, d2 = 4, d3 = 5, d4 = 6, d5 = 7;
LiquidCrystal lcd(rs, en, d2, d3, d4, d5);
 
int trigPin = 18;    //Trig
int echoPin = 19;    //Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!!!"); //this goes to colum 0 of row 0 by default

}
 
void loop()
{

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lcd.setCursor(0, 1);//column 0 of row 1
  lcd.print("Distance: ");
  lcd.print(cm);  
  delay(500);
  lcd.print("       ");
}

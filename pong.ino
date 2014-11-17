/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
#include <Servo.h> 
  
int pos = 90;    // variable to store the servo position 
int posv =80;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 Servo myservoV;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)  
   myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
   myservoV.attach(9);
     Serial.begin(9600); 
}
bool subindo = true;
// the loop routine runs over and over again forever:
void loop() {
   
  for(pos = pos; pos <= 130; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
  Serial.println(posv);  
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservoV.write(posv); 
    delay(30);                       // waits 15ms for the servo to reach the position 
    int sensorValue0 = analogRead(A0); 
    int sensorValue1 = analogRead(A1);
    if( posv >= 100) subindo = false;
   if( posv <= 60) subindo = true;
    if(subindo)
    {
        if(pos % 5 == 0) posv += 3;
    }
    else
    {
      if(pos % 5 == 0) posv -= 3;
    }
    if(sensorValue1 > 900) 
   { 
     break;
   }
  } 
  for(pos = pos; pos>=50; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    Serial.println(posv);  
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservoV.write(posv); 
    
    delay(30);                       // waits 15ms for the servo to reach the position
   int sensorValue0 = analogRead(A0); 
    int sensorValue1 = analogRead(A1); 
    
    if( posv >= 100) subindo = false;
   if( posv <= 60) subindo = true;
   
    if(subindo)
    {
        if(pos % 5 == 0) posv += 3;
    }
    else
    {
      if(pos % 5 == 0) posv -= 3;
    }
    
    if(sensorValue0 > 900)
   { 
     break;
   }
    //if(sensorValue1 > 900) break; 
  } 
}

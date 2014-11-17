#include <Servo.h> 
  
int pos = 90;  
int posv = 80;
Servo myservo;  
Servo myservoV;  

void setup() {                

   myservo.attach(3);  
   myservoV.attach(9);
}
bool subindo = true;

void loop() {
   
  for(pos = pos; pos <= 130; pos += 1)  
  {                                  
    myservo.write(pos);              
    myservoV.write(posv); 
    delay(30);                       

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

  } 
  for(pos = pos; pos>=50; pos-=1)     
  {                                
    myservo.write(pos);              
    myservoV.write(posv); 
    
   delay(30);            

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
    

  } 
}
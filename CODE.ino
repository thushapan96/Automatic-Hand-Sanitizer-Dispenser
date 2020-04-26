//this is the you want to upload


#include <Servo.h>
Servo servo1;
int trigPin = 9;    //connect trigpin of ultrasonic sensor to pin 9 on arduino
int echoPin = 8;    //connect echopin of ultrasonic sensor to pin 8 on arduino
long distance;
long duration;
 
void setup() 
{
  Serial.begin(115200);
servo1.attach(3);              // connect servo signal pin(orange color)  to arduino pin 3
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
 
void loop() {
 ultra();
 Serial.println(distance);
  servo1.write(180);
  if(distance <20)               //you can change this value as you hand position from ultralsonic sensor
   {  
  servo1.write(120);
  
  }
  
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }



  //lets upload the code to arduino ..

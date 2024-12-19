#include <Servo.h>
Servo Myservo;
#define trigPin 9// TrigPin of HC-SR04
#define echoPin 8// EchoPin of HC-SR04
#define MLa 4// left motor 1st pin
#define MLb 5// left motor 2nd pin
#define MRa 6// right motor 2nd pin
#define MRb 7// right motor 2nd pin
long duration, distance;

void setup() {
Serial.begin (9600);
pinMode(MLa, OUTPUT); //set motorPinsAS O/P
pinMode(MLb, OUTPUT);
pinMode(MRa, OUTPUT);
pinMode(MRb, OUTPUT);
pinMode(trigPin, OUTPUT);//set Trig |Pin As O/P To Transmit Waves
pinMode(echoPin, INPUT); // set Echo Pin As I/P To Receive Reflect Waves
Myservo.attach(10);
}
void loop() 
{
Serial.begin (9600);
digitalWrite(trigPin,LOW);
delayMicroseconds (2);
duration=pulseIn(echoPin,HIGH);//transmit waves FOR 10us
delayMicroseconds (10);
digitalWrite(trigPin,HIGH);//Receive Reflect Waves 
distance=duration/58.2; //Get Distance
Serial.print(distance);
delay (10);
if (distance >20)//Condition for Absence of Obstacle
{
Myservo.write(90);
digitalWrite(MRb,HIGH);//Move forward
digitalWrite(MRa,LOW); 
digitalWrite(MLb,LOW);
digitalWrite(MLa,HIGH);  
}
else if ((distance < 15)&&(distance > 0))//Condition for Absence of Obstacle
{
digitalWrite(MRb,LOW);//STOP
digitalWrite(MRa,LOW);
digitalWrite(MLb,LOW);
digitalWrite(MLa,LOW);
delay(100);

Myservo.write(0);
delay(500);
Myservo.write(180);
delay(500);

digitalWrite(MRb,LOW);//Turn Right
digitalWrite(MRa,HIGH);
digitalWrite(MLb,LOW);
digitalWrite(MLa,HIGH);
delay(500);
digitalWrite(MRb,LOW);//STOP
digitalWrite(MRa,LOW);
digitalWrite(MLb,LOW);
digitalWrite(MLa,LOW);
delay(100);
digitalWrite(MRb,HIGH);//move Right
digitalWrite(MRa,LOW);
digitalWrite(MLb,LOW);
digitalWrite(MLa,LOW);
delay(500);
}
}
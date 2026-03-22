#include <Servo.h>

const int trigPin = 6;
const int echoPin = 5;
long duration;
int distance;
 
Servo myServo;  

void setup() {
  myServo.attach(3);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() {
  distance = calculateDistance();
  myServo.write(0);

  if ( distance < 5){ 
    myServo.attach(3);
    myServo.write(160);
    delay(500);
    myServo.write(0);
    delay(1000);
    }
  else{
    myServo.detach();
    }
  }

int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); 

  // Calculating the distance
  distance= duration*0.034/2;
  return distance;
}

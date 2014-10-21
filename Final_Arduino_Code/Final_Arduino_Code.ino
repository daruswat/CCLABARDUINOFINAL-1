#include <Servo.h>

Servo myservo;
const int pingPin = 7;
int val = 0;

void setup() {
  pinMode(6, OUTPUT);
  delay(3000);

  pinMode(13, OUTPUT); // red LED
//  pinMode(1, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop(){
    digitalWrite(6, HIGH);
    delayMicroseconds(val);
    val = 4*analogRead(A5);
    digitalWrite(6, LOW);
    delayMicroseconds(val);

  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if(cm <= 15 && cm > 0) {
    myservo.write(150);
    digitalWrite(13, HIGH);
  } else if(cm <= 25 && cm > 15) {
    myservo.write(135);
    digitalWrite(13, LOW);
  } else if(cm <= 50 && cm > 25) {
    myservo.write(120);
    digitalWrite(13, LOW);
  } else if(cm <= 75 && cm > 50) {
    myservo.write(105);
    digitalWrite(13, LOW);
    
//     digitalWrite(6, HIGH);
//    delayMicroseconds(val);
//    val = 4*analogRead(A5);
//    digitalWrite(6, LOW);
//    delayMicroseconds(val);
    
    
    
   } else if(cm <= 100 && cm > 75) {
    myservo.write(90);
    digitalWrite(13, LOW);
  } else if(cm <= 150 && cm > 100) {
    myservo.write(90);
    digitalWrite(13, LOW);    
  } else if(cm <= 200 && cm > 150) {
    myservo.write(30);
    digitalWrite(13, LOW);
  } else {
    myservo.write(0);
    digitalWrite(13, LOW);
  }

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();


  //delay(200);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

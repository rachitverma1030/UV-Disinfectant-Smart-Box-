#include <Servo.h>
#include <NewPing.h>
int servoPin = 5;//11 ic pin
Servo Servo1;
char data = 0;

#define ECHO_PIN     2 //4 ic pin
#define TRIGGER_PIN  3 //5 ic pin
#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


int buzPin = 7;//13 ic pin
int led1Pin = A4; //23 ic pin
int led2Pin = A3; //24 ic pin
int led3Pin = A2; //25 ic pin
int led4Pin = A1; //26 ic pin
int led5Pin = A0; //27 ic pin
int UVledPin = A5; //28 ic pin
long cm;
int a = 0;
int b = 0;
int c = 0;
int x = 50;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(UVledPin, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(servoPin, LOW);
  digitalWrite(buzPin, LOW);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(led5Pin, LOW);
  digitalWrite(UVledPin, LOW);
  Serial.begin(9600);
  Servo1.attach(servoPin);
  delay(100);
  Servo1.write(0);
  delay(1000);
  Servo1.detach();
  delay(100);
  // Serial.println("SMART UV SANITIZER");
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(buzPin, HIGH);
    delay(50);
    digitalWrite(buzPin, LOW);
    delay(50);
  }
  delay(1000);
}
void loop() {
  //    if (Serial.available() > 0)
  //    {
  //      data = Serial.read();
  //
  //      if (data == 'R') {
  //        Servo1.write(0);
  //        delay(1000);
  //      }
  //      if (data == 'O') {
  //        Servo1.write(40);
  //        delay(1000);
  //      }
  //      if (data == 'C') {
  //        Servo1.write(0);
  //        delay(1000);
  //      }
  //
  //    }

  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  //Serial.print("Ping: ");
  //  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  //  Serial.println("cm");

  cm = uS / US_ROUNDTRIP_CM;

  if (cm > 20) {
    a = 0;
  }

  if (cm < 21 and a == 0) {
    a = 1;
    digitalWrite(buzPin, HIGH);
    delay(100);
    digitalWrite(buzPin, LOW);

    if (c == 0) {
      Servo1.attach(servoPin);
      delay(100);
      for (int j = 0; j < 50; j++) {
        Servo1.write(j);
        delay(100);
        //        Serial.print("x=");
        //        Serial.println(x);
      }
      
      //Servo1.write(50);
      //delay(1000);
      //      Servo1.detach();
      //      delay(100);
    }
    delay(1000);

    if (c == 1) {
      //  Servo1.attach(servoPin);
      delay(100);
      for (int j = 0; j < 50; j++) {
        x--;
        Servo1.write(x);
        delay(100);
        //        Serial.print("x=");
        //        Serial.println(x);
      }
      x = 50;
      Servo1.detach();
      delay(100);
      digitalWrite(buzPin, HIGH);
      delay(500);
      digitalWrite(buzPin, LOW);
      delay(100);
      digitalWrite(UVledPin, HIGH);
      for (int k = 0; k < 60; k++) {
        digitalWrite(led1Pin, HIGH);
        delay(500);
        digitalWrite(led1Pin, LOW);
        delay(500);
      }
      digitalWrite(led1Pin, HIGH);
      digitalWrite(buzPin, HIGH);
      delay(100);
      digitalWrite(buzPin, LOW);
      delay(100);
      for (int k = 0; k < 60; k++) {
        digitalWrite(led2Pin, HIGH);
        delay(500);
        digitalWrite(led2Pin, LOW);
        delay(500);
      }
      digitalWrite(led2Pin, HIGH);
      digitalWrite(buzPin, HIGH);
      delay(100);
      digitalWrite(buzPin, LOW);
      delay(100);
      for (int k = 0; k < 60; k++) {
        digitalWrite(led3Pin, HIGH);
        delay(500);
        digitalWrite(led3Pin, LOW);
        delay(500);
      }
      digitalWrite(led3Pin, HIGH);
      digitalWrite(buzPin, HIGH);
      delay(100);
      digitalWrite(buzPin, LOW);
      delay(100);
      for (int k = 0; k < 60; k++) {
        digitalWrite(led4Pin, HIGH);
        delay(500);
        digitalWrite(led4Pin, LOW);
        delay(500);
      }
      digitalWrite(led4Pin, HIGH);
      digitalWrite(buzPin, HIGH);
      delay(100);
      digitalWrite(buzPin, LOW);
      delay(100);
      for (int k = 0; k < 60; k++) {
        digitalWrite(led5Pin, HIGH);
        delay(500);
        digitalWrite(led5Pin, LOW);
        delay(500);
      }
      digitalWrite(led5Pin, HIGH);
      digitalWrite(UVledPin, LOW);
      delay(100);
      for (int k = 0; k < 5; k++) {
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, HIGH);
        digitalWrite(led4Pin, HIGH);
        digitalWrite(led5Pin, HIGH);
        digitalWrite(buzPin, HIGH);
        delay(1000);
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        digitalWrite(led4Pin, LOW);
        digitalWrite(led5Pin, LOW);
        digitalWrite(buzPin, LOW);
        delay(1000);
      }
      Servo1.attach(servoPin);
      delay(100);
      for (int j = 0; j < 50; j++) {
        Servo1.write(j);
        delay(100);
        //        Serial.print("x=");
        //        Serial.println(x);
      }
//      Servo1.write(50);
//      delay(1000);
      //      Servo1.detach();
      //      delay(100);
    }
    delay(1000);

    if (c == 2) {

      //   Servo1.attach(servoPin);
      delay(100);
      for (int j = 0; j < 50; j++) {
        x--;
        Servo1.write(x);
        delay(100);
        //        Serial.print("x=");
        //        Serial.println(x);
      }
      x = 50;
      Servo1.detach();
      delay(100);
      digitalWrite(buzPin, HIGH);
      delay(1000);
      digitalWrite(buzPin, LOW);
      delay(1000);
    }
    c++;
    //    Serial.print("c=");
    //    Serial.print(c);
    if (c > 2) {
      c = 0;
    }
  }
  delay(200);

}

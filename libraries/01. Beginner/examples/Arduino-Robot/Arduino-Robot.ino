/**
 * @file Arduino-Robot.ino
 * @brief Control the Arduino Robot
 * @version 1.0.0
 * 
 * @details
 * Connect the touch sensor to pin 8 and the LEDs to pins 11 and 13.
 * When the touch sensor is pressed, the LEDs will turn on and the servos will move.
*/

#include <Servo.h>

// declare servo objects
Servo myServo5;
Servo myServo6;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  myServo5.attach(5);
  myServo6.attach(6);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(8)) {
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    myServo5.write(0);
    myServo6.write(0);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    myServo5.write(90);
    myServo6.write(90);
    delay(1000);
  }
}
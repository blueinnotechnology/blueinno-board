/**
 * @file Servo-Sweep.ino
 * @brief Sweep the servo from 0 to 180 degrees
 * @version 1.0.0
 * 
 * @details Connect the servo to pin 9 and the servo will sweep from 0 to 180 degrees
*/

#include <Servo.h>

// Servo pin
#define SERVO_PIN 9

// Declare servo object and position variable
int pos;
Servo myServo;

// the setup function runs once when you press reset or power the board
void setup() {
  myServo.attach(9);
  pos = 0;
}

// the loop function runs over and over again forever
void loop() {
  // Sweep the servo from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15);
  }

  // Sweep the servo from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}
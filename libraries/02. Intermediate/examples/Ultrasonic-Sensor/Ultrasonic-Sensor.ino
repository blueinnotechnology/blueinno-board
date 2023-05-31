/**
 * @file Ultrasonic-Sensor.ino
 * @brief Read the distance from an ultrasonic sensor
 * @version 1.0.0
 * 
 * @details
 * Connect the ultrasonic sensor to pins 8 for echo and 9 for trig.
 * Print the distance from the ultrasonic sensor to the serial monitor.
*/

int trig = 9;
int echo = 8;
double velocity = 0.034;
int distance;
long duration;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200); // initialize serial communication at 115200 bits per second
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (velocity * duration) / 2; // distance = velocity * time

  Serial.print(distance);
  Serial.println(" cm");
}
/**
 * @file Touch-LEDs.ino
 * @brief Turn on the LEDs when the touch sensor is pressed
 * @version 1.0.0
 * 
 * @details 
 * Connect the touch sensor to pin 8 and the LEDs to pins 11 and 13. 
 * When the touch sensor is pressed, the LEDs will turn on.
*/

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(8, INPUT);
	pinMode(13, OUTPUT);
	pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
	// Read the touch sensor
	if (digitalRead(8)) {
		digitalWrite(13, HIGH);
		digitalWrite(11, HIGH);
		delay(1000);
		digitalWrite(13, LOW);
		digitalWrite(11, LOW);
		delay(1000);
	}
}
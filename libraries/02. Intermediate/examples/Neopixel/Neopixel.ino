/**
 * @file Neopixel.ino
 * @brief Blink a Neopixel
 * @version 1.0.0
 * 
 * @details
 * Connect a Neopixel to pin 6.
 * Blink the Neopixel.
*/
#include <Adafruit_NeoPixel.h>

#define PIN        6 // NeoPixel pin
#define NUMPIXELS 16 // NeoPixel ring size

// Note that for older NeoPixel strips you might need to change the third parameter
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500

void setup() {
	pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
	pixels.clear(); // Set all pixel colors to 'off'

	// The first NeoPixel in a strand is #0, second is 1, all the way up
	// to the count of pixels minus one.
	for (int i=0; i<NUMPIXELS; i++) { // For each pixel...
		// pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
		// Here we're using a moderately bright green color:
		pixels.setPixelColor(i, pixels.Color(0, 150, 0));
		pixels.show();   // Send the updated pixel colors to the hardware.
		delay(DELAYVAL); // Pause before next pass through loop
	}
}
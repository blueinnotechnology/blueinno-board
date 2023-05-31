/**
 * @file OLED.ino
 * @brief Display a animation on an OLED screen
 * @version 1.0.0
 * 
 * @details
 * Connect an OLED screen to the I2C bus.
 * Display a animation.
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 		// Reset pin if any
#define SCREEN_ADDRESS 0x3C // 0x3D or 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h);

// Used for testanimate function
#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2
#define LOGO_HEIGHT   32
#define LOGO_WIDTH    32

// Use https://diyusthad.com/image2cpp to generate your own logo_bmp
// 32x32px
const unsigned char logo_bmp [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x98, 0x19, 0x80, 0x00, 0x1c, 0x38, 0x00, 
	0x07, 0x9c, 0x19, 0xe0, 0x07, 0xbf, 0xfd, 0xe0, 0x06, 0x3f, 0xfc, 0x60, 0x18, 0xff, 0xff, 0x18, 
	0x19, 0xff, 0xff, 0x98, 0x19, 0xff, 0xff, 0x98, 0x19, 0xc7, 0xe3, 0x98, 0x19, 0xc7, 0xe3, 0x98, 
	0x19, 0xc7, 0xe3, 0x98, 0x0f, 0xc7, 0xe3, 0xf0, 0x07, 0xff, 0xff, 0xe0, 0x01, 0xff, 0xff, 0x80, 
	0x01, 0xff, 0xff, 0x80, 0x00, 0x38, 0x1c, 0x00, 0x00, 0x38, 0x1c, 0x00, 0x00, 0x38, 0x1c, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(; ; ); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  
  // Hello World Example
  // 	display.setTextSize(1);
  // 	display.setTextColor(WHITE);
  // 	display.setCursor(0, 10);
  // 	display.println("Hello, world!");
  // 	display.display();
  
  testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps
}

void loop() {
}

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
	int8_t f, icons[NUMFLAKES][3];
	
	// Initialize 'snowflake' positions
	for(f=0; f< NUMFLAKES; f++) {
		icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
		icons[f][YPOS]   = -LOGO_HEIGHT;
		icons[f][DELTAY] = random(1, 6);
		Serial.print(F("x: "));
		Serial.print(icons[f][XPOS], DEC);
		Serial.print(F(" y: "));
		Serial.print(icons[f][YPOS], DEC);
		Serial.print(F(" dy: "));
		Serial.println(icons[f][DELTAY], DEC);
	}
	
	for(; ; ) { // Loop forever...
		display.clearDisplay(); // Clear the display buffer
		
		// Draw each snowflake:
		for(f=0; f< NUMFLAKES; f++) {
			display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
		}

		display.display(); // Show the display buffer on the screen
		delay(50);        // Pause for 0.05 second
		
		// Then update coordinates of each flake...
		for(f=0; f< NUMFLAKES; f++) {
			icons[f][YPOS] += icons[f][DELTAY];
			// If snowflake is off the bottom of the screen...
			if (icons[f][YPOS] >= display.height()) {
				// Reinitialize to a random position, just off the top
				icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
				icons[f][YPOS]   = -LOGO_HEIGHT;
				icons[f][DELTAY] = random(1, 6);
			}
		}
	}
}
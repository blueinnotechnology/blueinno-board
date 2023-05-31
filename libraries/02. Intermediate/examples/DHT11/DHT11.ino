/**
 * @file DHT11.ino
 * @brief Read the temperature and humidity from a DHT11 sensor
 * @version 1.0.0
 * 
 * @details
 * Connect the DHT11 sensor to pin 5.
 * Print the temperature and humidity to the serial monitor.
*/
#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(1000);
  //The DHT11 returns at most one measurement every 1s
  float h = dht.readHumidity();
  //Read the moisture content in %
  float t = dht.readTemperature();
  //Read the temperature in degrees Celsius
  float f = dht.readTemperature(true);
  // true returns the temperature in Fahrenheit

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed reception"));
    return;
    //Returns an error if the pi pico does not receive any measurements
  }

  Serial.print("Humidite: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C, ");
  Serial.print(f);
  Serial.println("°F");
  //Transmits the received measurements to the serial terminal via USB
}
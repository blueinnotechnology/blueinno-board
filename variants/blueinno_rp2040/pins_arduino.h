// pins_arduino.h file

#pragma once

// pin definitions for the BlueInno RP2040 board V0.4
static const uint8_t D0 = (0u);
static const uint8_t D1 = (1u);
static const uint8_t D2 = (2u);
static const uint8_t D3 = (3u);
static const uint8_t D4 = (4u);
static const uint8_t D5 = (5u);
static const uint8_t D6 = (6u);
static const uint8_t D7 = (7u);
static const uint8_t D8 = (14u);
static const uint8_t D9 = (15u);
static const uint8_t D10 = (16u);
static const uint8_t D11 = (17u);
static const uint8_t D12 = (18u);
static const uint8_t D13 = (19u);
static const uint8_t D14 = (20u);
static const uint8_t D15 = (21u);
static const uint8_t D16 = (25u);

static const uint8_t A0 = (26u);
static const uint8_t A1 = (27u);
static const uint8_t A2 = (28u);
static const uint8_t A3 = (29u);

// LEDs
#define PIN_LED         (D16) // (25u)
#define LED_BUILTIN PIN_LED

// Serial 1
#define PIN_SERIAL1_TX  (D0) // (0u)
#define PIN_SERIAL1_RX  (D1) // (1u)

// Serial 2
#define PIN_SERIAL2_TX  (8u)
#define PIN_SERIAL2_RX  (9u)

// SPI 0
#define PIN_SPI0_MISO  (D4) // (4u)
#define PIN_SPI0_MOSI  (D7) // (7u)
#define PIN_SPI0_SCK   (D6) // (6u)
#define PIN_SPI0_SS    (D5) // (5u)

// SPI 1
#define PIN_SPI1_MISO  (12u)
#define PIN_SPI1_MOSI  (11u)
#define PIN_SPI1_SCK   (10u)
#define PIN_SPI1_SS  (13u)

// Wire 0
#define PIN_WIRE0_SDA  (D14) // (20u)
#define PIN_WIRE0_SCL  (D15) // (21u)

// Wire 1
#define PIN_WIRE1_SDA  (D12) // (18u)
#define PIN_WIRE1_SCL  (D13) // (19u)

#define SERIAL_HOWMANY (3u)
#define SPI_HOWMANY    (2u)
#define WIRE_HOWMANY   (1u)

#define PINS_COUNT          (21u)
#define NUM_DIGITAL_PINS    (21u)
#define NUM_ANALOG_INPUTS   (4u)
#define NUM_ANALOG_OUTPUTS  (0u)
#define ADC_RESOLUTION      (12u)

#define DigitalPinToPinName(p) (p)

static const uint8_t SS = PIN_SPI0_SS;
static const uint8_t MOSI = PIN_SPI0_MOSI;
static const uint8_t MISO = PIN_SPI0_MISO;
static const uint8_t SCK = PIN_SPI0_SCK;

// IOT module support
#define IOT_RESETN		(23u)
#define SerialIOT		Serial3
#define SerialHCI	    Serial2

#define SERIAL3_TX      (8u)
#define SERIAL3_RX      (9u)
   
#define IOT_GPIO9		(24u)

#define SPIWIFI_SS		(13u)
#define SPIWIFI_ACK		(22u)
#define SPIWIFI_RESET	(IOT_RESETN)
#define SPIWIFI 		(SPI1)

#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial2

#define USB_MAX_POWER	(500)
#include "Arduino.h"
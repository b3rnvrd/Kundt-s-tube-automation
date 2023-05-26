// Pilotage du Moteur pas à pas avec utilisation de l'écran tactile

#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

#define STMPE_CS 8
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000

#define SD_CS 4

// brochage de la carte moteur pas à pas (A4988)
#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36


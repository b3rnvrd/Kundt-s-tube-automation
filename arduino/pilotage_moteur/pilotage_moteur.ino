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

char data;

void setup() {
  Serial.begin(9600);
  Serial.println("Test A4988");

  digitalWrite( EN_A4988, HIGH );
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );

  pinMode( EN_A4988, OUTPUT );
  pinMode( DIR_A4988   , OUTPUT );
  pinMode( STEP_A4988  , OUTPUT );
  pinMode( MS1_A4988, OUTPUT );
  pinMode( MS2_A4988   , OUTPUT );
  pinMode( MS3_A4988  , OUTPUT );
  pinMode( RST_A4988, OUTPUT );
  pinMode( SLP_A4988   , OUTPUT );


  digitalWrite( MS1_A4988, LOW );
  digitalWrite( MS2_A4988, LOW );
  digitalWrite( MS3_A4988, LOW );
}

void loop() {
        int i = 0;
      
        digitalWrite( DIR_A4988   , HIGH); // Direction gauche
        digitalWrite( STEP_A4988  , LOW);  // Initialisation de la broche step
        digitalWrite( EN_A4988, LOW );
        digitalWrite( RST_A4988, HIGH );
      
        // Avance de 200 pas
        for ( i = 0; i < 100; i++) {
          Serial.println( i );
          digitalWrite( STEP_A4988, HIGH );
          delay( 10 );
          digitalWrite( STEP_A4988, LOW );
          delay( 10 );
        }
      
        // déblocage de l'axe moteur
        Serial.println("Deblocage axe");
        digitalWrite( EN_A4988, HIGH );
        digitalWrite( RST_A4988, LOW );
        digitalWrite( SLP_A4988, HIGH );

 
  // Fin et blocage du programme
  // Presser reset pour recommander
  Serial.println("Fin de programme");
  while ( true );
}

#include "pilotage_ecran.h"

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define SD_CS 4

unsigned long affichageTexte() {
  unsigned long start = micros();
  tft.setCursor(0, 0);
  
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  tft.println("Bonjour, j'arrive a piloter cet ecran");
  tft.setTextSize(2);
  tft.println("La j'ecris plus gros");
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_RED);
  tft.println("Et la en rouge");
  tft.setTextColor(ILI9341_RED);
  tft.println("");

  return micros() - start;
}

void setupSerialEcran() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
      
  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  
  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);

  Serial.print(F("Text                     "));
  Serial.println(affichageTexte());
  delay(3000);

  Serial.println(F("Done!"));

}

#include "pilotage_ecran.h"

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define SD_CS 4

void setupEcran() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
}

unsigned long affichageTexte(bool texte_stop = false) {
  unsigned long start = micros();
  tft.setCursor(0, 0);
  if (!texte_stop)
  {
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(9);
    tft.println("ARRET DU MOTEUR");
  }
  else
  {
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
  }
  return micros() - start;
}

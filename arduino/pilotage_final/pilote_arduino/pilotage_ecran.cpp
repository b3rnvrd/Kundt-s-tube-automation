#include "pilotage_ecran.h"

#define SD_CS 4

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setupEcran() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  affichageLiaison(false);
}

void affichageMesureEnCours() {
  String texteMesure = "Mesure en cours";

  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println(texteMesure);
  tft.setCursor(0, 0);
  for (int i = 0; i < 3; i++) {
    tft.println(texteMesure += ".");
    tft.setCursor(0, 0);
    delay(500);
  }
  tft.setCursor(0, 0);
  texteMesure = "Mesure en cours   ";

}

void affichageMesures(String data) {
  tft.setRotation(4);
  tft.setCursor(0, 0);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println(data);
}

void affichageStopManuel(bool arret_manuel) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(4);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(5);
  if (arret_manuel == true)
    tft.println("Arret du moteur en cours");
  else
    tft.println("Moteur a l'arret");
}

void affichageLiaison(bool is_open) {
  String liaison;
  if (is_open)
    liaison = "Liaison      ouverte";
  else
    liaison = "Liaison      fermee";
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.println(liaison);
}

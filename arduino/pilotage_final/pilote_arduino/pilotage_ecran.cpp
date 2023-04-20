#include "pilotage_ecran.h"

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define SD_CS 4

void setupEcran() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
}

void affichageMesureEnCours(bool texte_stop = false) {
  tft.setCursor(0, 0);

  if (texte_stop)  //Affichage bouton urgence
  {
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(9);
    tft.println("ARRET DU MOTEUR");
  }
  else  //Affichage mesure en cours
  {
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.println("Mesure en cours");
    tft.println("Mesure en cours.");
    tft.println("Mesure en cours..");
    tft.println("Mesure en cours...");
  }
}

void affichageMesures(char data) {

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.println(data);
}

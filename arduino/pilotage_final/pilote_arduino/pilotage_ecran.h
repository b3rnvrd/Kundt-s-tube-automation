#ifndef PILOTAGE_ECRAN_H
#define PILOTAGE_ECRAN_H

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

void affichageMesureEnCours();
void setupEcran();
void affichageMesures(String data);
void affichageStopManuel(bool arret_manuel);
void affichageLiaison(bool is_open);

#endif
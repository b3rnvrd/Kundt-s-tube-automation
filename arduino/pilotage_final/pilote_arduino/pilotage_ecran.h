#ifndef PILOTAGE_ECRAN_H
#define PILOTAGE_ECRAN_H

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10



unsigned long affichageTexte(bool texte_stop = true);
void setupEcran();

#endif

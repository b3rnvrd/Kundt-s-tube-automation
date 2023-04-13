#include "pilotage_ecran.h"
#include "pilotage_moteur.h"
char data;

void setup() {
  setupSerialMoteur();
  setupEcran();
}

void loop() {
  while (Serial.available()) {
    data = Serial.read();

    switch (data) {
      case 'd':
        avanceDroite();
        affichageTexte();
        break;
      case 'g':
        avanceGauche();
        affichageTexte();
        break;
      case 's':
        arretMoteur();
        affichageTexte(true);
        delay(5);
        break;
    }
  }
}

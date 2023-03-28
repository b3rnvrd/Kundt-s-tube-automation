#include "pilotage_ecran.h"
#include "pilotage_moteur.h"
char data;
void setup() {
  setupSerialMoteur();
  setupSerialEcran();
}

void loop() {
  while (Serial.available()) {
    data = Serial.read();

    switch (data) {
      case 'd':
        avanceDroite();
        break;
      case 'g':
        avanceGauche();
        break;
      case 'p':
        arretMoteur();
        affichageTexte(true);
        delay(5000);
        break;
    }
    affichageTexte();
    
  }

}

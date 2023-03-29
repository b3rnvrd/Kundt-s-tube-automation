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
        affichageTexte(true);
        break;
      case 'g':
        avanceGauche();
        affichageTexte(true);
        break;
      case 'p':
        arretMoteur();
        affichageTexte();
        delay(5);
        break;
    }
    //affichageTexte();
    
  }

}

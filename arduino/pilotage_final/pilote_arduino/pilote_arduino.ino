#include "pilotage_ecran.h"
#include "pilotage_moteur.h"

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
        break;
    }
  }

}

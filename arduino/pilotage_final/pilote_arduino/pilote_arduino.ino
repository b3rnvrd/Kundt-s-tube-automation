#include "pilotage_ecran.h"
#include "pilotage_moteur.h"

char data;

void setup() {
  setupSerialMoteur();
  setupEcran();
}

void loop() {
  while (Serial.available()) 
  {
    data = Serial.read(); //Lecture des données sur le port série

    switch (data) {
      //Demande de déplacement à droite
      case 'd':
        avanceDroite();
        affichageTexte();
        break;
        
      //Demande de déplacement à gauche 
      case 'g':
        avanceGauche();
        affichageTexte();
        break;

      //Demande d'arrêt d'urgence
      case 's':
        arretMoteur();
        affichageTexte(true);
        break;
    }
  }
}

test

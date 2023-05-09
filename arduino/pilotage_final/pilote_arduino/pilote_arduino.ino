#include "pilotage_ecran.h"
#include "pilotage_moteur.h"

char data;
String donnees_a_afficher;

void setup() {
  setupSerialMoteur();
  setupEcran();
}

void loop() {

  affichageMesures(donnees_a_afficher);
  delay(100000);
  while (Serial.available())
  {
    data = Serial.read(); //Lecture des données sur le port série

    switch (data) {
      //Demande de déplacement à droite
      case 'd':
        avanceDroite();
        affichageMesureEnCours();
        break;

      //Demande de déplacement à gauche
      case 'g':
        avanceGauche();
        affichageMesureEnCours();
        break;

      //Demande d'arrêt d'urgence
      case 's':
        arretMoteur();
        affichageStopManuel(true);
        break;
    }
    arretMoteur();
  }
  while (Serial.available()) {
    donnees_a_afficher = Serial.read();
    affichageMesures(donnees_a_afficher);
    affichageStopManuel(false);

  }
}

#include "pilotage_ecran.h"
#include "pilotage_moteur.h"

char data;
String donnees_a_afficher;
int delimiteur, delimiteur_1;

void setup() {
  setupSerialMoteur();
  setupEcran();
}

void loop() {
  while (Serial.available())
  {
    data = Serial.read(); //Lecture des données sur le port série

    switch (data) {
      //Ouverture liaison
      case 'o':
        affichageLiaison(true);
        Serial.flush();
        break;

      //Fermeture liaison
      case 'f':
        affichageLiaison(false);
        Serial.flush();
        break;
     
      //Demande de déplacement à droite
      case 'd':
        avanceDroite();
        affichageMesureEnCours();
        Serial.flush();
        break;

      //Demande de déplacement à gauche
      case 'g':
        avanceGauche();
        affichageMesureEnCours();
        Serial.flush();
        break;

      //Demande d'arrêt d'urgence
      case 's':
        arretMoteur();
        affichageStopManuel(true);
        Serial.flush();
        break;
    }
    arretMoteur();
  }
  while (Serial.available()) {
    donnees_a_afficher = Serial.readString();
    delimiteur = donnees_a_afficher.indexOf("$");
    delimiteur_1 = donnees_a_afficher.indexOf("$", delimiteur + 1);
    donnees_a_afficher = donnees_a_afficher.substring(delimiteur + 1, delimiteur_1);
    donnees_a_afficher.trim();
    affichageMesures(donnees_a_afficher);
    //affichageStopManuel(false);
  }
}

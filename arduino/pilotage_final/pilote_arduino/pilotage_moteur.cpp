#include "pilotage_moteur.h"

// brochage de la carte moteur pas à pas (A4988)
#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36

#define nb_pas 10

void setupSerialMoteur() {
  //Initialisation de la liaison série à 115200 bauds
  Serial.begin(115200);

  //DEFINITION DE TOUTES LES BROCHES EN SORTIE
  pinMode( EN_A4988, OUTPUT );
  pinMode( DIR_A4988   , OUTPUT );
  pinMode( STEP_A4988  , OUTPUT );
  pinMode( MS1_A4988, OUTPUT );
  pinMode( MS2_A4988   , OUTPUT );
  pinMode( MS3_A4988  , OUTPUT );
  pinMode( RST_A4988, OUTPUT );
  pinMode( SLP_A4988   , OUTPUT );
  pinMode(LED_BUILTIN, OUTPUT);

  //Initialisation des broches MS1, MS2 et MS3 à LOW = 1 pas entier
  digitalWrite( MS1_A4988, LOW );
  digitalWrite( MS2_A4988, LOW );
  digitalWrite( MS3_A4988, LOW );

  //Initialisation des broches ENABLE, RESET et SLEEP
  digitalWrite( EN_A4988, HIGH );
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );
}

void avanceGauche() {

  digitalWrite( DIR_A4988   , LOW); // Direction GAUCHE

  // Initialisation des broches STEP et RESET
  digitalWrite( STEP_A4988  , LOW);
  digitalWrite( RST_A4988, HIGH );

  //Enable actif
  digitalWrite( EN_A4988, LOW );

  // Avance de 30 pas = 1 cm

  for (int i = 0; i < 10; i++) {
    digitalWrite( STEP_A4988, HIGH );
    delay( 20 );
    digitalWrite( STEP_A4988, LOW );
    delay( 20 );
  }

  // Broche ENABLE inactive
  digitalWrite( EN_A4988, HIGH );

  //Vérification visuelle de la bonne réception de l'ordre avec le clignotement de la DEL de la carte
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);

}

void avanceDroite() {

  digitalWrite( DIR_A4988   , HIGH); // Direction DROITE

  // Initialisation des broches STEP et RESET
  digitalWrite( STEP_A4988  , LOW);
  digitalWrite( RST_A4988, HIGH );

  //Enable actif
  digitalWrite( EN_A4988, LOW );

  // Avance de 30 pas = 1 cm
  for ( int i = 0; i < 10; i++) {
    digitalWrite( STEP_A4988, HIGH );
    delay( 20 );
    digitalWrite( STEP_A4988, LOW );
    delay( 20 );
  }

  // Broche ENABLE inactive
  digitalWrite( EN_A4988, HIGH );

  //Vérification visuelle de la bonne réception de l'ordre avec le clignotement de la DEL de la carte
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}

void arretMoteur() {
  // Broche ENABLE inactive
  digitalWrite( EN_A4988, HIGH );
}

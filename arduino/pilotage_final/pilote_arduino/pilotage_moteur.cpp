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

void setupSerialMoteur() {
  Serial.begin(115200);



  pinMode( EN_A4988, OUTPUT );
  pinMode( DIR_A4988   , OUTPUT );
  pinMode( STEP_A4988  , OUTPUT );
  pinMode( MS1_A4988, OUTPUT );
  pinMode( MS2_A4988   , OUTPUT );
  pinMode( MS3_A4988  , OUTPUT );
  pinMode( RST_A4988, OUTPUT );
  pinMode( SLP_A4988   , OUTPUT );


  digitalWrite( MS1_A4988, LOW );
  digitalWrite( MS2_A4988, LOW );
  digitalWrite( MS3_A4988, LOW );
  digitalWrite( EN_A4988, HIGH );   // Initialisation de la broche ENABLE
  digitalWrite( RST_A4988, LOW );   // Initialisation de la broche RESET
  digitalWrite( SLP_A4988, HIGH );  // Initialisation de la broche SLEEP
  pinMode(LED_BUILTIN, OUTPUT);


}

void avanceGauche() {
  int i = 0;

  digitalWrite( DIR_A4988   , LOW); // Direction GAUCHE
  digitalWrite( STEP_A4988  , LOW); // Initialisation de la broche STEP
  digitalWrite( RST_A4988, HIGH );
  digitalWrite( EN_A4988, LOW );    // Broche ENABLE activee

  // Avance de 1 pas
  for ( i = 0; i < 100; i++) {
    digitalWrite( STEP_A4988, HIGH );
    delay( 20 );
    digitalWrite( STEP_A4988, LOW );
    delay( 20 );
  }

  // blocage de l'axe moteur
  digitalWrite( EN_A4988, HIGH );   // Broche ENABLE desactivee
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );

  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)^1);

}

void avanceDroite() {
  int i = 0;

  digitalWrite( DIR_A4988   , HIGH); // Direction DROITE
  digitalWrite( STEP_A4988  , LOW);  // Initialisation de la broche STEP
  digitalWrite( RST_A4988, HIGH );
  digitalWrite( EN_A4988, LOW );     // Broche ENABLE activee

  // Avance de 1 pas
  for ( i = 0; i < 100; i++) {
    digitalWrite( STEP_A4988, HIGH );
    delay( 20 );
    digitalWrite( STEP_A4988, LOW );
    delay( 20 );
  }

  // blocage de l'axe moteur
  digitalWrite( EN_A4988, HIGH );   // Broche ENABLE desactivee
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );

  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)^1);
}

void arretMoteur() {
  digitalWrite( EN_A4988, HIGH );   // Broche ENABLE desactivee
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );
}

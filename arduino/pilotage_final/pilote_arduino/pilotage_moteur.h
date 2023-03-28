#ifndef PILOTAGE_MOTEUR_H
#define PILOTAGE_MOTEUR_H

// brochage de la carte moteur pas à pas (A4988)
#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36

char data;

void setupSerialMoteur();
void avanceGauche();
void avanceDroite();
void arretMoteur();

#endif

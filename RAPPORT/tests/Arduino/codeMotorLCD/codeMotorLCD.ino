// Pilotage du Moteur pas à pas
// brochage de la carte moteur pas à pas (A4988)
#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36

void setup()
{
  pinMode(RST_A4988, OUTPUT);
  digitalWrite(RST_A4988,LOW); // start RAZ du driver A4988
  delayMicroseconds(100);
  digitalWrite(RST_A4988,HIGH); // RAZ du driver A4988
  pinMode(EN_A4988, OUTPUT);
  digitalWrite(EN_A4988,HIGH);  // Driver A4988 désactivé
  pinMode(SLP_A4988, OUTPUT);
  digitalWrite(SLP_A4988,HIGH); // mode SLEEP désactivé
  pinMode(MS1_A4988, OUTPUT);
  pinMode(MS2_A4988, OUTPUT);
  pinMode(MS3_A4988, OUTPUT);
  digitalWrite(MS1_A4988,LOW);  // Full Step
  digitalWrite(MS2_A4988,LOW);  // Full Step
  digitalWrite(MS3_A4988,LOW);  // Full Step
  pinMode(STEP_A4988, OUTPUT);
  digitalWrite(STEP_A4988,LOW);
  pinMode(DIR_A4988, OUTPUT);
  digitalWrite(DIR_A4988,LOW);

  digitalWrite(EN_A4988,LOW);  // Driver A4988 activé
}

bool stepHigh= false;
  
void avance()
{
  stepHigh= !stepHigh;
  digitalWrite(STEP_A4988,stepHigh);
}

void loop(void)
{
  digitalWrite(DIR_A4988,LOW);
  for(int i=0; i<200;i++)
  {  avance();
     delay(10);
  }
  digitalWrite(DIR_A4988,HIGH);
  for(int i=0; i<200;i++)
  {  avance();
     delay(10);
  }
}

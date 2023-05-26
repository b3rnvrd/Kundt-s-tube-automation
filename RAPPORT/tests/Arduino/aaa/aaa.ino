char data;

#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36

void setup() {
  Serial.begin(115200);
  Serial.println("Test A4988");

  digitalWrite( EN_A4988, HIGH );
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );

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

  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  while (Serial.available()) {
    data = Serial.read();

    switch (data) {
      case 't':
        avanceMoteur();
        break;
      case 'p':
        arretMoteur();
        break;
    }
  }
}

void avanceMoteur() {
  int i = 0;

  digitalWrite( DIR_A4988   , HIGH); // Direction droite
  digitalWrite( STEP_A4988  , LOW);  // Initialisation de la broche step
  digitalWrite( EN_A4988, LOW );
  digitalWrite( RST_A4988, HIGH );

  // Avance de 200 pas
  for ( i = 0; i < 50; i++) {
    digitalWrite( STEP_A4988, HIGH );
    delay( 10 );
    digitalWrite( STEP_A4988, LOW );
    delay( 10 );
  }

  // déblocage de l'axe moteur
  digitalWrite( EN_A4988, LOW );
  digitalWrite( RST_A4988, HIGH );
  digitalWrite( SLP_A4988, LOW );

  digitalWrite(LED_BUILTIN, HIGH);
}

void arretMoteur() {
    // déblocage de l'axe moteur
  digitalWrite( EN_A4988, HIGH );
  digitalWrite( RST_A4988, LOW );
  digitalWrite( SLP_A4988, HIGH );
  
  digitalWrite(LED_BUILTIN, LOW);
}

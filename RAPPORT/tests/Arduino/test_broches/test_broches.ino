
// brochage de la carte moteur pas à pas (A4988)
#define EN_A4988   22
#define MS1_A4988  24
#define MS2_A4988  26
#define MS3_A4988  28
#define RST_A4988  30
#define SLP_A4988  32
#define STEP_A4988 34
#define DIR_A4988  36


void setup() {
  Serial.begin(9600);
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
}

void loop() {

  int i = 0;
  digitalWrite( DIR_A4988   , LOW); // Direction gauche
  digitalWrite( STEP_A4988  , LOW);  // Initialisation de la broche step
  digitalWrite( EN_A4988, LOW );
  digitalWrite( RST_A4988, HIGH );

  for ( i = 0; i < 600; i++) {
    Serial.println( i );
    digitalWrite( STEP_A4988, HIGH );
    delay( 10 );
    digitalWrite( STEP_A4988, LOW );
    delay( 10 );
  }

  digitalWrite( EN_A4988, LOW );
  digitalWrite( RST_A4988, HIGH );
  digitalWrite( SLP_A4988, LOW );

  while (true);
}

 
// PWM est connecté au pin 3.
const int pinPwm = 3;

// DIR est connecté au pin 2.
const int pinDir = 2;

const int SC1 = 4; // sortie du capteur de pression 4
const int SC2 = 5; // sortie du capteur de pression 5 
const int SCO = 2; // sortie du codeur 
const float VitMax = 255; // vitesse max du moteur
const int TC1Max = 1023; // tension Max 5V = 1023
const int TC2Max = 1023;
int TC1;
int TC2;
int TCO;
int VitM1; 
int VitM2;
void setup() 
{
    // Initialise les pins PWM et DIR comme sorties digitals.
  pinMode(pinPwm, OUTPUT);
  pinMode(pinDir, OUTPUT);

  Serial.begin(9600); // on lance la communication avec la console
}

void loop() 
{ 
  TC1 = analogRead(SC1);
  TC2 = analogRead(SC2);
  TCO = digitalRead(SCO);
  VitM1 = TC1*VitMax/TC1Max;
  VitM2 = TC2*VitMax/TC2Max;

  Serial.println("----------------------");
  Serial.print("TC1 = ");
  Serial.println(TC1);
  Serial.print("VitM1 = ");
  Serial.println(VitM1);
  
  Serial.println();

  Serial.print("TC2 = ");
  Serial.println(TC2);
  Serial.print("VitM2 = ");
  Serial.println(VitM2);

  Serial.println();
  
  Serial.print("Codeur = ");
  Serial.println(TCO);
  
  Serial.println("----------------------");
  
  Serial.println();
  Serial.println();
  
  if (TC1 =! 0 and TC2 == 0)
  {
    analogWrite(pinPwm,VitM1); //On définit la vitesse de rotation
    digitalWrite(pinDir, LOW); //On fait tourner le moteur 
  }
  if (TC2 =! 0 and TC1 == 0) 
  {
    analogWrite(pinPwm,VitM2); //On définit la vitesse de rotation
    digitalWrite(pinDir, HIGH); //On fait tourner le moteur dans l'autre sens
  }
  
}

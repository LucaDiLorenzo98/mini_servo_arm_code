#include <Servo.h>

// Dichiarazione dei servo
Servo servoBase;
Servo servoFirstArm;
Servo servoSecondArm;
Servo servoGripper;

// Variabili per le posizioni dei servo (escludendo il servoBase a 360°)

int posizioneDefaultFirstArm = 90;
int posizioneDefaultSecondArm = 0;
int posizioneDefaultGripper = 20;

int posizioneFirstArm = 90;
int posizioneSecondArm = 0;
int posizioneGripper = 20;

void setup() {
  servoBase.attach(3);
  servoFirstArm.attach(2);
  servoSecondArm.attach(4);
  servoGripper.attach(5);

  servoFirstArm.write(posizioneDefaultFirstArm);
  servoSecondArm.write(posizioneDefaultSecondArm);
  servoGripper.write(posizioneDefaultGripper);

  delay(1000);
}

// Funzione per muovere un servo da una posizione iniziale a una finale con delay 15
void muoviServo(Servo& servo, int daPos, int aPos) {
  if (daPos < aPos) {
    for (int pos = daPos; pos <= aPos; pos++) {
      servo.write(pos);
      delay(15);
    }
  } else {
    for (int pos = daPos; pos >= aPos; pos--) {
      servo.write(pos);
      delay(15);
    }
  }
}


void closeGripper() {
  servoGripper.write(0);
}

void openGripper() {
  servoGripper.write(90);
}

void takeCubeOnSlide() {

  openGripper();
  
  muoviServo(servoFirstArm, posizioneFirstArm, 145);
  posizioneFirstArm = 145;

  delay(500);

  closeGripper();

  delay(500);

  muoviServo(servoFirstArm, posizioneFirstArm, posizioneDefaultFirstArm);
  posizioneFirstArm = posizioneDefaultFirstArm;

  delay(500);

  // move base to right 
  servoBase.write(70);
  delay(440);
  servoBase.write(90);

  delay(1000);

  muoviServo(servoSecondArm, posizioneSecondArm, 50);
  posizioneSecondArm = 50;

  delay(1000);

  muoviServo(servoFirstArm, posizioneFirstArm, 130);
  posizioneFirstArm = 130;

  delay(1000);

  openGripper();

  delay(200);

  muoviServo(servoSecondArm, posizioneSecondArm, 90);
  posizioneSecondArm = 90;

  muoviServo(servoFirstArm, posizioneFirstArm, posizioneDefaultFirstArm);
  posizioneFirstArm = posizioneDefaultFirstArm;

  delay(1000000000);

  /*
  servoBase.write(110);
  delay(500);
  servoBase.write(90);
  */
}

void loop() {
  takeCubeOnSlide();
}

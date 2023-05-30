#include <Servo.h>

int N2OFillOut = 11;
int N2OVentOut = 10;
int FuelVentOut = 9;
int PressurantOut = 5;


int N2OFillSignal = 8;
int SlowVentSignal = 7;
int FastVentSignal = 6;
int PressurantSignal = 4;


Servo N2OFillValve;
Servo N2OVentValve;
Servo FuelVentValve;
Servo PressurantValve;



void setup() {
  N2OFillValve.attach(N2OFillOut);
  N2OVentValve.attach(N2OVentOut);
  FuelVentValve.attach(FuelVentOut);
  PressurantValve.attach(PressurantOut);
  
  N2OFillValve.write(0);
  PressurantValve.write(0);
  N2OVentValve.write(180);
  FuelVentValve.write(180);
  
}

void loop() {
  
  if (digitalRead(N2OFillSignal) == HIGH) {
    N2OFillValve.write(180);
  }

  if (digitalRead(N2OFillSignal) == LOW) {
    N2OFillValve.write(0);
  }
  
  if (digitalRead(PressurantSignal) == HIGH) {
    PressurantValve.write(180);
  }

  if (digitalRead(PressurantSignal) == LOW) {
    PressurantValve.write(0);
  }

  if (digitalRead(FastVentSignal) == LOW) {
    N2OVentValve.write(180);
    FuelVentValve.write(180);
  }

  if (digitalRead(FastVentSignal) == HIGH) {
    if (digitalRead(SlowVentSignal) == HIGH) {
      N2OVentValve.write(0);
    }
    else if (digitalRead(SlowVentSignal) == LOW) {
      N2OVentValve.write(110);
      FuelVentValve.write(0);
    }  
  }
}

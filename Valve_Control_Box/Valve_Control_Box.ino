#include <Servo.h>

int fillValveSignal = 4;
int fillValveOut = 3;
int ventValveSignal = 11;
int ventValveOut = 5;
int pressuriseValveSignal = 12;
int pressuriseValveOut = 6;


Servo fillValve;
Servo ventValve;
Servo pressuriseValve;



void setup() {
  fillValve.attach(fillValveOut);
  ventValve.attach(ventValveOut);
  pressuriseValve.attach(pressuriseValveOut);
  
  fillValve.write(0);
  ventValve.write(120);
  
}

void loop() {
  
  if (digitalRead(fillValveSignal) == HIGH) {
    fillValve.write(180);
  }
  
  if (digitalRead(ventValveSignal) == HIGH) {
    ventValve.write(180);
  }

  if (digitalRead(pressuriseValveSignal) == HIGH) {
    ventValve.write(180);
  }

  if (digitalRead(fillValveSignal) == LOW) {
    fillValve.write(0);
  }
  
  if (digitalRead(ventValveSignal) == LOW) {
    ventValve.write(0);
  }

  if (digitalRead(pressuriseValveSignal) == LOW) {
    fillValve.write(0);
  }
  

  
}

#include <Stepper.h>

const int pin0=D0;
const int pin1=D1;
const int pin2=D2;
const int pin3=D3;
const int control=A0;

Stepper stepper(200, D0, D1, D2, D3);
int previous=0;

void setup(){
  stepper.setSpeed(10);
  pinMode(A0, INPUT);
}

void loop(){
  float val=analogRead(A0);
  float a=val-previous;
  a = constrain(a, 0, 4095);
  float b=map(a, 0, 4095, 0, 200);
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(10);
  delay(500);
  // remember the previous value of the sensor
  previous = val;
}

/*
• Change the control pins
• Change the speed
• Change the number of steps per turn
• Map the potentiometer output to 0-200*/

#include <Stepper.h>
/*Stepper stepper(#steps, pin_coil_1, pin_coil_2, pin_coil_3, pin_coil_4);
• #steps: number of steps per revolution (200)
• pin_coil_{1,2,3,4} the pin used for each coil (D0, D1, D2, D3)*/

// change this to the number of steps on your motor
#define STEPS 100
int input_pin = A0;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
}

void loop() {
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
}

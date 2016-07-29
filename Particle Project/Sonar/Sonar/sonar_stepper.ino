#include<Stepper.h>

const int readPin = A0;
int count = 1;
int num = 0;
Stepper stepper(200, D0, D1, D2, D3);

void setup(){
	stepper.setSpeed(30);
	pinMode(readPin, INPUT);
}

void loop(){
	while(Serial.available() && num < 150) {
		// read two values
		Serial.read();
		Serial.read();

		// first turning 90 degrees
		if(num < 50) {
			stepper.step(count);
			num += count;
		}
		// then turing 180 degrees
		else {
			stepper.step(-count);
			num += count;
		}

		int distance =  analogRead(readPin);
		// Serial.print(distance);
		int t = constrain(distance, 0, 4095);
		distance = map(t, 0,4095, 100, 15);
		int angleEachTurn = 18 * num;
		int disfromObj = distance * 10;

		delay(150);
		// DEC (decimal, or base 10)
		Serial.print(angleEachTurn, DEC);
		Serial.print(","); // print angle
		Serial.print(disfromObj);
		Serial.print("."); // print distance
	}
}

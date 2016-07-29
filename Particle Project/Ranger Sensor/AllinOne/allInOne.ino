// Pin for sound
const int soundPin = D0;
// Pin for lights
const int GreenPin = D2;
const int RedPin = D3;
int sensores;
int meteres;

void redOff() {
  digitalWrite(RedPin, LOW);
}
void greOff() {
  digitalWrite(GreenPin, LOW);
}
void brightness(int lightPin, int num) {
  // int ext = map(num, 20, 150, 0, 255);
  int ext = map(num, 0, 4095, 0, 255);
  analogWrite(lightPin, ext);
}

void setup(){
// initialize the digital pin as an output:
  pinMode(soundPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop(){
    // ranger sensor connected A1
    sensores = analogRead(A1);
    int ss = constrain(sensores, 0, 4095);
    sensores = map(ss, 0, 4095, 4095, 0);
    // float voltage = 70/(sensores + 6);
    int distance = map(ss, 0, 4095, 150, 20);
    Serial.print("Ranger sensor:");
    Serial.print(distance);
    delay(200);
    Serial.print("\n");

    // potentiometer connected A0
    meteres = analogRead(A0);
    int mm = constrain(meteres, 0, 4095);
    // float voltage = map(mm, 0, 4095, 0, 3.3); // 0.8 mv per steps
    // float approxDis = 70/ meteres -6; // voltage to distance
    Serial.print("potentiometer set distance:");
    Serial.print(mm);
    delay(200);
    Serial.print("\n");

    // dis = constrains(meteres, meteres - 100, meteres + 100);
    // compare sensores and approxDis OR ss and mm
    // if (sensores >= approxDis - 5 && sensores <= approxDis + 5) {
    if (sensores >= mm - 200 && sensores <= mm + 200) {
      greOff();
      redOff();
      tone(soundPin, 500, 500);
      delay(200);
    }

    // if (sensores < approxDis - 5) {
    else if (sensores < mm - 200) {
      // digitalWrite(GreenPin, HIGH);
      noTone(D0);
      redOff();
      // brightness(GreenPin, abs(sensores - approxDis));
      brightness(GreenPin, abs(sensores - mm));
    }
    // else if (sensores < approxDis + 5) {
    else if (sensores > mm + 200) {
      // digitalWrite(RedPin, HIGH);
      noTone(D0);
      greOff();
      // brightness(RedPin, abs(sensores - approxDis));
      brightness(RedPin, abs(sensores - mm));
    }
    // delay(200);
  }

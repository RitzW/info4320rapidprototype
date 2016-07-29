#include<math.h>
const int audioInput = A0;
const int dac=DAC;
const int num_samples=128;
int sine_samples[num_samples];
const float PI =3.14;

void setup(){
  pinMode(audioInput,INPUT);
  pinMode(dac, OUTPUT);
  setADCSampleTime(ADC_SampleTime_3Cycles);
  Serial.begin(9600);
  /*for (int i = 0; i < num_samples; i++) {
    sine_samples[i] = 2047*(sin(2*PI*i/(1.0*num_samples)) + 1.0);
  }*/
}

int audio = 0;
int newAudio;
int temp;
int16_t samples[24000];
void loop(){
  /*for(int i =0;i<num_samples;i++){
    analogWrite(dac, sine_samples[i]);
    temp = map(sine_samples[i],0,4096,0,255);
    Serial.write(temp);

  }*/
  for(int i=0;i<24000;i++){
    audio  = analogRead(audioInput);
    samples[i]=audio;
    delayMicroseconds(108);
  }
  for(int i =0;i<24000;i++){
    analogWrite(dac, samples[i]);
    temp = map(samples[i],0,4096,0,255);
    Serial.write(temp);
    delayMicroseconds(108);
  }

  /*audio = analogRead(audioInput);
  newAudio = map(audio,0,4096,0,255);
  Serial.write(newAudio);*/

}

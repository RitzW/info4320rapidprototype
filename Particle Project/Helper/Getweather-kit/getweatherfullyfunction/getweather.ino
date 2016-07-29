// INFO 4320
// Mar 2 2016 Discusson
// This example gets weather data with TCPClient and prints the termperature using the aJSON library.
// @author Ian Arawjo
#include "aJSON.h"

TCPClient client;
String s = "";

void setup()
{
  // Make sure your Serial Terminal app is closed before powering your device
  Serial.begin(9600);

  // Now open your Serial Terminal, and hit any key to continue!
  while(!Serial.available()) Particle.process();
  Serial.println("connecting...");
  if (client.connect("api.openweathermap.org", 80))
  {
    Serial.println("connected");
    client.println("GET /data/2.5/weather?q=Ithaca,ny&appid=44db6a862fba0b067b1930da0d769e98");
    client.println("Host: api.openweathermap.org");
    client.println("Content-Length: 0");
    client.println(); // send msg
  }
  else
  {
    Serial.println("connection failed");
  }
}
void loop()
{
  if (client.available())
  {
    char c = client.read();
    s += c;
    Serial.print(c);
  }
  if (!client.connected())
  {
    Serial.println();

    Serial.println("disconnecting....\n\n");
    client.stop();

    aJsonObject* root = aJson.parse(strdup(s.c_str()));
    aJsonObject* main = aJson.getObjectItem(root, "main");
    aJsonObject* temp = aJson.getObjectItem(main, "temp");

    // Print the frame rate, which is an integer
    float valtemp = temp->valuefloat;
    Serial.printf("Temperature is currently %f \n", valtemp);

    aJson.deleteItem(root); // this takes care of all subobjects

    for(;;) {
      Particle.process();
    }
  }
}

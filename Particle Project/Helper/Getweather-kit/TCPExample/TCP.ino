// EXAMPLE TCPClient USAGE from Particle docs
/*
    This code GETs data from a url and prints
    the (RAW) result to the Serial console.

*/
TCPClient client;

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
String json_string = "";
void loop()
{
  if (client.available())
  {
    char c = client.read();
    // Serial.print(c);
    json_string += C;
  }
  if (!client.connected())
  {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    for(;;) Particle.process();
  }
}

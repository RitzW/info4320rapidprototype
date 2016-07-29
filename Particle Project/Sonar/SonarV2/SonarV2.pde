// Etch-a-Sketch
// Adapted for INFO 4320
//
// Based on
// by Trevor Shannon
//
// based on Graph 
// by David A. Mell

import processing.serial.*;

Serial port;
int DELIMITER = '.';
int NEXT_TOKEN = 'N';
float scaling = 0.2;

class coordinate
{
  int angle, range;
};

coordinate last_point = new coordinate();
coordinate current_point = new coordinate();

void setup()
{
  
  String first_valid_data;
  // Set window size;
  size(512, 512);
  // List all the port on the machine;
   println(Serial.list());
  // open the first port
  // If you know the name of the port used by the Arduino board, you
  // can specify it directly like this.
  //port = new Serial(this, "COM1", 9600);
  port = new Serial(this, Serial.list()[1], 9600);
  // force more data to come in
  port.write(NEXT_TOKEN);

  // clear the screen;
  background(0);
}

void keyPressed()
{
  // clear the screen when a key is pressed
  background(0);
}

void draw()
{
  //port.write(NEXT_TOKEN);
  String current_data = port.readStringUntil(DELIMITER);

  // if we find the delimiter we process the data
  if (current_data != null)
  {
    // retrieve the new X and Y coordinate;
    parse_data(current_data);
    
    // request more data
    port.write(NEXT_TOKEN);

    // set the color to white;
    stroke(255);
    // draw the line;
    // line(last_point.x, last_point.y, current_point.x, current_point.y);
    ellipse(256 + cos(radians(current_point.angle))*current_point.range, 512 + sin(radians(current_point.angle))*current_point.range, 5, 5);
  }
}

void parse_data(String buff)
{
    int index;
    String angle_string;
    String range_string;
    
    // remove the trailling dot
    buff = buff.substring(0, buff.length() - 1);
    // look for the comma between X and Y
    index = buff.indexOf(",");
    // print(buff);
    // fetch the X string
    angle_string = buff.substring(0, index);
    // fetch the Y string
    range_string = buff.substring(index+1, buff.length());
    // if the strings are not empty
    if ((angle_string != "") && (range_string != ""))
    { 
      // remember the current point
      last_point.angle = current_point.angle;
      last_point.range = current_point.range;
      
      // update the current point with the new values
      current_point.angle = int(-float(angle_string)/10.0 - 45);
      current_point.range = int(int(range_string)*scaling);
      //println(current_point.range);
    }
}
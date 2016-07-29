// Etch-a-Sketch
// Adapted for INFO 4320
//
// Based on
// by Trevor Shannon
//
// based on Graph 
// by David A. Mellis

import processing.serial.*;

Serial port;
int window_width = 700;
int window_height = 300;
int scale = 5;
int max_data_size = window_width/scale;
boolean waiting_for_data;
  
// index to store the data
int[] data = new int[max_data_size];

void setup()
{
  // Set window size;
  size(700, 300);
  // List all the port on the machine;
  println(Serial.list());
  // open the first port
  // If you know the name of the port used by the Arduino board, you
  // can specify it directly like this.
  //port = new Serial(this, "COM1", 9600);
  port = new Serial(this, "/dev/cu.usbmodem1411", 9600);
  port.buffer(max_data_size);
  waiting_for_data = true;
  // clear the screen
  background(0);
}

void keyPressed()
{
  // clear the screen when a key is pressed
  background(0);
  redraw_background();
  stroke(255,0,0);
  fill(255,0,0);
  ellipse(10,10,10,10);
  // force more data to come in
  for (int i = 0; i < max_data_size; i++)
  {
     data[i] = 0;
  }
  waiting_for_data = true;
}

void draw()
{  
  print(data);
  redraw_background();    
  if (waiting_for_data)
  {
    stroke(255,0,0);
    fill(255,0,0);
    ellipse(10,10,10,10);
  }
  else
  {
    stroke(0,255,0);
    fill(0,255,0);
    ellipse(10,10,10,10);
  }
  stroke(255);
  noFill();
  beginShape();
  curveVertex(0, 272 - data[0]);
  for (int i = 0; i < max_data_size; i++)
  {
    curveVertex((i)*scale, 275 - data[i]);
  }
  curveVertex(max_data_size - 1, 275 - data[max_data_size - 1]);
  endShape();
}

void redraw_background()
{
  // clear the screen
  background(0);
  // create the X axis 
  stroke(128,128,255);
  line(0, window_height/2, window_width, window_height/2);
  // create the tick marks on X
  for(int i = 0; i < window_width/(scale*10); i++)
  {
    line(i*scale*10, window_height/2 + 2, i*scale*10, window_height/2 - 2);
  }
  stroke(64,64,128);
  // create max and min 
  line(0,(window_height - 255)/2,window_width,(window_height - 255)/2);
  line(0,(window_height + 255)/2,window_width,(window_height + 255)/2);
}

void serialEvent(Serial myPort) {
  for (int i = 0; i < max_data_size; i++)
  {
     data[i] = myPort.read();
  }
  waiting_for_data = false;
}
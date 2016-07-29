/**

  An example of parsing with the aJSON library:
    https://github.com/interactive-matter/aJson

  The included version of aJSON has been modified
  to compile in Particle Dev with Spark Core libraries.

  Use: Type anything to return part of the JSON tree.
*/

// Include the aJSON library
#include "aJSON.h"

// A test JSON string.
/*char* json_string = "{ \
    \"name\": \"Samsung LED\", \
    \"format\": { \
        \"type\":       \"rect\", \
        \"width\":      1920, \
        \"height\":     1080, \
        \"interlace\":  false, \
        \"frame rate\": 24 \
    } \
}";*/

/*"main": {
        "temp": 269.453,
        "pressure": 987.25,
        "humidity": 58,
        "temp_min": 269.453,
        "temp_max": 269.453,
        "sea_level": 1026.53,
        "grnd_level": 987.25
    },*/


bool once = true;

// Start listening for serial input
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Type anything to return part of the JSON tree (only once):
  if (Serial.available() && once) {

    // Parse the JSON string...
    aJsonObject* root = aJson.parse(json_string);

    // Get the item called "name" at the root of the tree.
    aJsonObject* main = aJson.getObjectItem(json_string, "main");

    // Print the value of "name"
    Serial.print("Name is ");
    Serial.println(main->valuestring);

    // Get the frame rate within the "format" item:
    aJsonObject* format = aJson.getObjectItem(main, "temp");
    aJsonObject* frame_rate = aJson.getObjectItem(format, "frame rate");

    // Print the frame rate, which is an integer
    int rate = frame_rate->valueint;
    Serial.printf("Frame rate is %d \n", rate);

    // Cleanup (!! IMPORTANT)
    // * IF you don't do this, your Photon might run out of memory and flash red. *
    aJson.deleteItem(root); // this takes care of all subobjects

    // Stop checking for Serial
    // * We cannot do Serial.end() here because of the delay in printf. *
    once = false;
  }

}

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers
************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Engine.h"

Engine game;

///////////////////////////////////////////////////////////////////////////////
////////////////SETUP//////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void setup()   
{                
 Serial.begin(9600);
 game.init();
}

///////////////////////////////////////////////////////////////////////////////
////////////////LOOP///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void loop()
{
 game.update(); // Main engine update event.

}

///////////////////////////////////////////////////////////////////////////////
////////////////FUNCTIONS//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

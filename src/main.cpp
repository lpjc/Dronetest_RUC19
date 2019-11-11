#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>

 
int lcdc = 16;
int lcdr = 2;
 
LCD myLCD(lcdc,lcdr); //columns and rows for the LCD screen

void setup()
{
Serial.begin(9600);
myLCD.setupLCD();
}

void loop(){
    
 myLCD.liftOffText();
}

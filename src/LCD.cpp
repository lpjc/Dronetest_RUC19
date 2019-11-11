#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <wire.h>
#include <LiquidCrystal.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
using namespace std;


LCD::LCD(int lcdc, int lcdr)

{
    this->lcdc = lcdc;
    this->lcdr = lcdr;
    
    int lcdColumns = 16;
    int lcdRows = 2;
}


int lcdColumns = 16;
int lcdRows = 2;
/*

void LCDscreen::setupLCD() {      //initialzing the LCD screen
int lcdColumns = 16;
int lcdRows = 2;
// set the LCD number of columns and rows

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
/*this->*/

LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  

void LCD::setupLCD() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

/*void LCD::loop() {
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
  
}
*/

void LCD::liftOffText() {
  lcd.setCursor(0, 0);
  lcd.print("DRONE LIFT OFF!!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("DRONE LIFT OFF!!");
  delay(1000);
  lcd.clear(); 

}

void LCD::missionPadOneText() {

  lcd.setCursor(0, 0);
  lcd.print("GOING TO MISSION PAD ONE!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("GOING TO MISSION PAD ONE!");
  delay(1000);
  lcd.clear(); 
}
void LCD::missionPadTwoText() {
 lcd.setCursor(0, 0);
  lcd.print("GOING TO MISSION PAD TWO!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("GOING TO MISSION PAD TWO!");
  delay(1000);
  lcd.clear(); 
}
void LCD::missionPadThreeText() {
     lcd.setCursor(0, 0);
  lcd.print("GOING TO MISSION PAD THREE!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("GOING TO MISSION PAD THREE!");
  delay(1000);
  lcd.clear(); 
}
void LCD::missionPadFourText() {
 lcd.setCursor(0, 0);
  lcd.print("GOING TO MISSION PAD FOUR!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("GOING TO MISSION PAD FOUR!");
  delay(1000);
  lcd.clear(); 
}
void LCD::missionPadEnd() {

     lcd.setCursor(0, 0);
  lcd.print("COURSE DONE, TIME TO LAND!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("COURSE DONE, TIME TO LAND!");
  delay(1000);
  lcd.clear(); 
}







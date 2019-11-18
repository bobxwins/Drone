#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <wire.h>
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


LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  

void LCD::setupLCD() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}



void LCD::takeOffText() {
  lcd.setCursor(0, 0);
  lcd.print("DRONE TAKING OFF");
  delay(1000);
  lcd.clear();
   lcd.setCursor(0, 1);
  lcd.print("DRONE TAKING OFF");
  delay(1000);
  lcd.clear();
 
 

}


void LCD::landText() {

  lcd.setCursor(0,0);
  lcd.print("DRONE Landing!");
  delay(1000);
  lcd.clear(); 
  lcd.setCursor(0,1);
  lcd.print("DRONE Landing!");
  delay(1000);
  lcd.clear(); 


}






#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <joystick.h>
#include <ButtonListener.h>
#include "WiFi.h"
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include "AsyncUDP.h"
#include <wire.h>


String ssid = "TELLO-FE2F6B";
String password = "";

Drone drone(ssid, password);
Joystick joystick(15, 34, 35); // pins: btn, x, y

 
  
int lcdc = 16;
int lcdr = 2;

 

LCD myLCD(lcdc,lcdr); //columns and rows for the LCD screen

Drone flyve (bool flying);

void setup()
{
  Serial.begin(9600);
  myLCD.setupLCD();


  drone.joystick = &joystick; 

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
    delay(1000);
     
  }

  joystick.addButtonListener(&drone);
  
  drone.connect();
  drone.setIp ("192.168.10.1");

  
}

void loop()
{ 
   
   
  joystick.loop();
  drone.loop();;

 myLCD.takeOffText();
    
} 


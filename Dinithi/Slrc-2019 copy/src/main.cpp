#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>

#include<globalspace.h>
#include<FunctionList.h>
#include<Calculations.h>
#include<Drive.h>
#include<grid.h>
#include<interrupts.h>
#include<Line following&color.h>
#include<OLED.h>
#include<pin_Modes.h>
#include<MeasureDistance.h>
//#include<debug.h>
unsigned long start_time=0;
unsigned long current_time=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  Wire.begin();
  pinModes();
  OLEDsetup();
  tofSetup();
  Serial.println("Done Setup");
  // put your setup code here, to run once:
}

void loop() {
start_time = millis();
Gridupdate_3();
Cellcolorarray_3();
CellTRavel_update();
NumberTheGrid();
DetectColoredCells();
Pillval=150;
CalculateColOrder();
CalculateRBGSquares();
current_time=millis();
Serial.println(current_time);
for (int a=0;a<8;a++){
  for (int b=0; b<8 ; b++){
    Serial.print(CellTravelColor[a*8+b]);
    Serial.print(" ");
  }
  Serial.println();

}
//detectcolour();
// digitalWrite(8,HIGH);
// Serial.print(analogRead(S1));
// Serial.print(",");
// Serial.print(analogRead(S2));
// Serial.print(",");
// Serial.print(analogRead(S3));
// Serial.print(",");
// Serial.print(analogRead(S4));
// Serial.print(",");
// Serial.print(analogRead(S5));
// Serial.print(",");
// Serial.print(analogRead(S6));
// Serial.print(",");
// Serial.print(analogRead(S7));
// Serial.print(",");
// Serial.print(analogRead(S8));
// Serial.print(",");
// Serial.println();
// detectcolour();
// current_time=millis();
// Serial.println(current_time);
while(1){}
 
  // put your main code here, to run repeatedly:
}
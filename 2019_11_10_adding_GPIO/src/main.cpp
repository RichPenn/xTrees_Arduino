#include <Arduino.h>
#include <Wire.h>
#include <OneObject.h>
#include <AllObjects.h>

using namespace std;

bool use_I2C_Bus = false;  // true for I2C -- false for gpio pins
int I2C_Address = 0x27;    // set for actual hardware address

AllObjects xTrees( use_I2C_Bus, I2C_Address );

void setup()
{
  xTrees.set_objStatus( 0, true,  0,  6,  99, 125);
  xTrees.set_objStatus( 1, true,  1,  7, 100,  50);
  xTrees.set_objStatus( 2, true,  2,  8, 100,  75);
  xTrees.set_objStatus( 3, true,  3,  9, 202,  84);
  xTrees.set_objStatus( 4, true,  4, 10, 100,  77);
  xTrees.set_objStatus( 5, true,  5, 11,  75, 150);
  xTrees.set_objStatus( 6, true,  6, 12, 211,  99);
  xTrees.set_objStatus( 7, true,  7, 13, 120,  80);

  if ( ! use_I2C_Bus)
  {
    pinMode(  6, OUTPUT);    
    pinMode(  7, OUTPUT);
    pinMode(  8, OUTPUT);
    pinMode(  9, OUTPUT);
    pinMode( 10, OUTPUT);
    pinMode( 11, OUTPUT);
    pinMode( 12, OUTPUT);
    pinMode( 13, OUTPUT);
  }

  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Serial.write("\n\nStarting a new loop \n\n");
/*
  for (int ijk = 0; ijk <= 3; ijk++)
  {
    xTrees.set_1_L2HON(90);
    xTrees.set_1_H2LON(90);
  }

  for (int ijk = 0; ijk <= 3; ijk++)
  {
    xTrees.set_1_L2HOFF(90);
    xTrees.set_1_H2LOFF(90);
  }

  xTrees.set_allON(2000);

  xTrees.set_H2LOFF(200);
  xTrees.set_H2LON(200);
  xTrees.set_H2LOFF(200);

  xTrees.set_L2HON(200);
  xTrees.set_L2HOFF(200);
  xTrees.set_L2HON(200);

  for (int ijk = 0; ijk <= 5; ijk++)
  {
    xTrees.set_allOFF(300);
    xTrees.set_allON(100);
  }

  xTrees.set_Flicker(5000, 150);

  xTrees.set_2_H2LON(50);
  xTrees.set_2_H2LON(50);
  xTrees.set_2_H2LON(50);
  xTrees.set_2_H2LON(50);
  xTrees.set_2_H2LON(50);

  xTrees.set_L2HON(200);
  xTrees.set_H2LOFF(200);

  xTrees.set_2_L2HON(50);
  xTrees.set_2_L2HON(50);
  xTrees.set_2_L2HON(50);
  xTrees.set_2_L2HON(50);
  xTrees.set_2_L2HON(50);

  xTrees.set_H2LON(200);
  xTrees.set_L2HOFF(200);

  xTrees.set_OddAndEven(20000, 1000);
*/
  xTrees.set_allOFF(1000);
  xTrees.set_2_fromCenter(10000, 500);
}; 
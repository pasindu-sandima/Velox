#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include "Adafruit_PWMServoDriver.h"
#include "nRF24L01.h"
#include "RF24.h"

#include<globalspace.h>
#include<FunctionList.h>
#include<Calculations.h>
#include<Drive.h>
#include<grid.h>
#include<interrupts.h>
#include<Line following_color.h>
#include<OLED.h>
#include<pin_Modes.h>
#include<MeasureDistance.h>
#include<NRF.h>
#include<Servo.h>
#include<debug.h>
unsigned long start_time=0;
unsigned long current_time=0;



void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("Started");
  Serial2.println("Started");

  Wire.begin();
  TCCR1B &= ~(1<<CS11);//to set 7.5kHz f to pin 11
  TCCR1A |= (1<<WGM11); // resolution to 10 bits of pins 10,11
  TCCR4B &= ~(1<<CS41);//to set 7.5kHz f to pin 8
  TCCR4A |= (1<<WGM41); // resolution to 10 bits of pins 6,7,8
  pinModes();
  // OLEDsetup();
  initialize_OLED();
  Print_Velox();
  tofSetup();
  servosetup();
  initNRF();
  Serial.println("Done Setup");
  while(digitalRead(button1)){}
  Buzz(150);
  Task2();
  Buzz(50);
  delay(100);
  Buzz(50);
  delay(100);
  Buzz(50);
  delay(100);
  Buzz(50);
  delay(100);
  while(true){}
  //GridSolve();
  //EnterArea2();
  // AccStraight();
  //   delay(150);
  //   indicatered1();
  //   delay(2000);
  //   indicategreen1();
  //   delay(2000);
  //   indicateblue1();
  //   delay(2000);
  //   delay(50);
  //   TurnRight();
  //   rspeed=500;
  //   lspeed=500;
  //   while(true){
  //       if (digitalRead(SRF)==HIGH){
  //           break;
  //       }
  //       lineFollow();
  //   }
  //   CorrectPosition();
  //   Brake();
  //   delay(100);
  //   TurnRight();
  //   Brake();
    
  // EnteringArea1();
  // LeavingArea1();
  // EnterArea2();
  // FinishTask();
  // while (true)
  // {
  //   /* code */
  // }
  
  
//************
  // uptoPillars();
  // Task2();
  // //To Area 1
  // AccStraight();
  // delay(150);
  // TurnRight();
  // delay(150);
  // AccStraight();
  // delay(150);
  // TurnRight();
  // delay(150);
  // rspeed=500;
  // lspeed=500;
  // while(true){
  //     if (digitalRead(SRF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }
  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnRight();
  // Brake();
  // delay(100);
  // //Entering into Area 1
  // AssARMdown();
  // delay(100);
  // rspeed=400;
  // lspeed=400;
  // while(true){
  //     lineFollow(); 
  //     if (n==8){
  //         Brake();
  //         break;
  //     }
        
  // }
  // delay(100);
  // AssARMup();
  // drive(-300,-300);
  // while(true){
  //     if((digitalRead(SLB)==HIGH)||(digitalRead(SLB)==HIGH)){
  //         Brake();
  //         break;
  //     }
  // }
  // delay(100);
  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnRightSlow();
  // //Leaving Area 1
  // rspeed=300;
  // lspeed=300;
  // while(true){
  //     if (digitalRead(SLF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }

  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnLeftSlow();
  // delay(100);
  // rspeed=300;
  // lspeed=300;
  // while(true){
  //     if (digitalRead(SLB)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }

  // while(true){
  //     if (digitalRead(SLF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }
  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnLeftSlow();
  // delay(100);
  // //Area 2 Line
  // rspeed=300;
  // lspeed=300;
  // while(true){
  //     if (digitalRead(SLF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }
  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnLeftSlow();
  // delay(100);
  // countright=0;
  // attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
  // attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
  // while(true){
  //   lineFollow();
  //   if(countright>2000){
  //     Brake();
  //     break;
  //   }
  // }
  // AssARMdown();
  // delay(100);
  // MagnetRelease();
  // delay(100);
  // drive(-300,-300);
  // while(true){
  //     if((digitalRead(SLB)==HIGH)||(digitalRead(SLB)==HIGH)){
  //         Brake();
  //         break;
  //     }
  // }
  // delay(100);
  // CorrectPosition();
  // Brake();
  // delay(100);
  // TurnLeftSlow();
  // MagnetNormal();
  // AssARMup();
  // indicatered2();
  // rspeed=500;lspeed=500;
  // while(true){
  //     if (digitalRead(SRF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }
  // CorrectPosition500();
  // delay(100);
  // TurnRight();
  // while(true){
  //     if (digitalRead(SRF)==HIGH){
  //         break;
  //     }
  //     lineFollow();
  // }
  // CorrectPosition500();
  // delay(100);
  // TurnRight();
  // delay(100);
  // FirstLineIndication();
  // MoveOneNode();
  // SecondLineIndication();
  // rspeed=800;
  //   lspeed=800;
  //   while(true){
  //       lineFollow();
  //       if (n==8){
  //           break;
  //       }
  //       if(n==0){
  //           Brake();
  //           while(true){}

  //       }
  //   }
  //   countForward(1800); 

  
  




  



























  
  // // Pillars();
  // GridSolve();
  // Buzz(50);
  // delay(100);
  // Buzz(50);
  // delay(100);
  // Buzz(50);
  // delay(100);
  // Buzz(50);
  // delay(100);
  // while(true){}
  // rspeed=500;
  // lspeed=500;
  // while(digitalRead(button1)){}
  // Buzz(100);
  // TurnCoinOne();
  // delay(500);
  // TurnCoinTwo();
  // delay(500);
  // TurnCoinThree();
  // delay(500);
  // TurnDoorAttach();
  // delay(500);
  // while(true){}

  // Kp=10;
  // Kd=0;
  // while (true){
  //   while(digitalRead(button1)){
  //     OLED_Display(String(Kp)+" , "+String(Kd));
  //     if(digitalRead(button2)){}
  //     else{
  //       Buzz(150);
  //       Kp+=1;
  //     }
  //     if(digitalRead(button3)){}
  //     else{
  //       Buzz(150);
  //       Kd+=5;
  //     }

  //   }
  //   Buzz(300);
  //   while(digitalRead(button1)){
  //     OLED_Display(String(lspeed)+" , "+String(rspeed));
  //     if(digitalRead(button2)){}
  //     else{
  //       Buzz(150);
  //       lspeed+=5;
  //     }
  //     if(digitalRead(button3)){}
  //     else{
  //       Buzz(150);
  //       rspeed+=5;
  //     }

  //   }
  //   Buzz(300);
  //   while(true){
  //     lineFollow();
  //     if(n==0){
  //       Brake();
  //       break;
  //     }
  //   }
  // }
  
  //GridSolve();
  //Task();
  //GridSolve();
  // digitalWrite(whiteleft,HIGH);
  // while(digitalRead(button1)){}
  // Buzz(200);
  // digitalWrite(whiteleft,LOW);
  // digitalWrite(whiteright,HIGH);
  // while(digitalRead(button1)){}
  // Buzz(200);
  // digitalWrite(whiteright,LOW);
  // digitalWrite(redled,HIGH);
  // while(digitalRead(button1)){}
  // Buzz(200);
  // digitalWrite(redled,LOW);
  // digitalWrite(greenled,HIGH);
  // while(digitalRead(button1)){}
  // Buzz(200);
  // digitalWrite(greenled,LOW);
  // digitalWrite(blueled,HIGH);
  // while(digitalRead(button1)){}
  // Buzz(200);
  // digitalWrite(blueled,LOW);
  //while(1){}
}

void loop() {
  // TurnLeftSlow();
  // delay(1000);
}
  //MoveForward(300,315);//400/420
// Pillars();
// OLED_Display(String(Pillval));
// while(1){}

  

  // TurnRightSlow();
  // delay(1000);
// while(true){
//   lineFollow();
//   if (n==8){
//     break;
//   }
// }
// countForward(1700);
// while(1){}
// while(digitalRead(button1)){}
// AssARMdown();
// delay(200);
// MagnetRelease();
// digitalWrite(blueled,HIGH);
// MagnetNormal();
// AssARMup();




// for (uint16_t pulselen = Testing1; pulselen < Testing2; pulselen++){
//         pwm.setPWM(Testing, 0, pulselen);
//         delay(5);
//     }

  // detectcolour();
  // delay(200);
  // Turn180();
  // delay(1000);
  
  // TurnRight45();
  // delay(1000);
  // TurnCoinOne();
  // delay(100);
  // TurnLeft45();
  // delay(1000);
  //lineFollow();
  // Turn180();
  // delay(1000);
  //TurnDoorAttach();
  //delay(500);
  // TurnCoinOne();
  // delay(500);
  // TurnCoinTwo();
  // delay(500);
  // TurnCoinThree();
  // delay(500);
  // TurnDoorAttach();
  // while(1){}
  //*******
  //Pillars();
  // Gridupdate_4();
  // OLED_Display(String(CNr)+","+String(CNc)+",            "+String(Face));
  // Cellcolorarray_3();
  // CellColor[4][0]=4;
  // //delay(4000);
  
  // CellTRavel_update();
  // NumberTheGrid();
  // DetectColoredCells();
  // Buzz(150);
  // delay(400);
  // // digitalWrite(redled,HIGH);
  // // OLED_Display(String(Red[0])+","+String(Red[1])+",   "+String(Red[2])+","+String(Red[3])+",   "+String(Red[4])+","+String(Red[5]));
  // // delay(1000);
  // // digitalWrite(blueled,HIGH);
  // // OLED_Display(String(Blue[0])+","+String(Blue[1])+",   "+String(Blue[2])+","+String(Blue[3])+",   "+String(Blue[4])+","+String(Blue[5]));
  // // delay(1000);
  // // digitalWrite(greenled,HIGH);
  // // OLED_Display(String(Green[0])+","+String(Green[1])+",   "+String(Green[2])+","+String(Green[3])+",   "+String(Green[4])+","+String(Green[5]));
  // // delay(1000);
  // // Buzz(150);
  // // delay(400);
  // CalculateColOrder();
  // Pillval=180;
  // CalculateRBGSquares();
  // //OLED_Display(String(MovetoCells[0][0])+","+String(MovetoCells[0][1])+",         "+String(MovetoCells[1][0])+","+String(MovetoCells[1][1])+",         "+String(MovetoCells[2][0])+","+String(MovetoCells[2][1]));
  // delay(500);
  // DetachCoins();
  // Buzz(100);
  // delay(50);
  // Buzz(100);
  // DNr=4;
  // DNc=0;
  // GoToNode();
  // while (1)
  // {
  //   /* code */
  // }
  //*********
  // Serial2.println("Hii Goose");
  // delay(500);
  //  Gridupdate_3check();
  //  Cellcolorarray_3();
  //  CellTRavel_update();
  //  DetectColoredCells();
  //  for (int a=0;a<3;a++){
  // for (int b=0; b< 2; b++){
  //   Serial.print(Green[a*2+b]);
  //   Serial.print(" ");
  // }
  // Serial.println();
  //  }
  //  while(1){}
  

  // TurnCoinOne();
  // delay(500);
  // TurnCoinTwo();
  // delay(500);
  // TurnCoinThree();
  // delay(500);
  // TurnDoorAttach();
  // delay(1500);
  // getTOFReading();
  // delay(300);
  // coinnum=1;
  // CoinArm15();
  // OLED_Display("Hii");
  // MoveOneNode();
  // Brake();
  // delay(500);
  // Face=0;
  // CNr=0;
  // CNc=0;
  // DNr=4;
  // DNc=7;
  // GoToNode();
  // while(1){
  //   TurnRight();
  //   while (digitalRead(button1)){}
  //   TurnLeft();
  //   while(digitalRead(button2))
  //   Turn180();
  //   while(digitalRead(button3)){}

    
  // }
  // Pillars();
  // OLED_Display(String(Pillval));
  // while (1){
  //    coinnum=1;
  //    CoinArm15();
  //    delay(1500);
  //    coinnum=2;
  //    CoinArm15();
  //    delay(1500);
  //    coinnum=3;
  //    CoinArm15();
  //    delay(2500);
  // Buzz(100);
  //   AssARMup();
  //   //while(digitalRead(button1)){}
  //   Buzz(500);
  //   delay(100);
    // MoveForward(200,200);
    // delay(3000);
    
    // Brake();
    // delay(400);

    // Buzz(150);
    // delay(1000);
    // AssARMdown();
    // //while(digitalRead(button2)){}
    // Buzz(150);
  //  //}
  
   //while(1){}
  // getTOFReading();
  // delay(100);
//  Turn180();
//  delay(1000);
  

// detectcolour();
// //Serial.println(colour);
// // OLED_print(20);
// OLED_Display(String(red)+" , "+String(blue)+","+String(green)+",       "+String(colour));  
//   //MagnetNormal();
  //******************
//MoveOneNode();
//digitalWrite(blueled,HIGH);

//  while(true){
//    //Face=3;
//   //  CNr=0;
//   //  CNc=0;
//   //  DNr=2;
//   //  DNc=2;
//   //  GoToNode();
//   for(int i=0;i<3;i++){
//       MoveOneNode();
//   }
//     // for(int i=0;i<4;i++){
//     //   detectcolour();
//       //OLED_Display(String(colour));
//       //MoveOneNode();
    
//     while(digitalRead(button1)){}
//     delay(1000);
//  }

// // //   //OLED_Display(String(digitalRead(SLF))+","+String(digitalRead(SRF))+","+String(digitalRead(SLB))+","+String(digitalRead(SRB)));
// // //   // delay(50);
//   }
// }
 //
//TurnLeft();
//  TurnRight();
//  Turn180();
// Gridupdate_3_test();
//******************
  // delay(1000);
  // Serial.println(countright);
  // delay(50);
  // digitalWrite(buzzer,HIGH);
  // digitalWrite(greenled,HIGH);
  // while(digitalRead(button1)){}
  // digitalWrite(buzzer,LOW);
  // digitalWrite(greenled,LOW);
  // digitalWrite(redled,HIGH);
  // while(digitalRead(button2)){}
  // digitalWrite(redled,LOW);
  // digitalWrite(whiteright,HIGH);
  // digitalWrite(whiteleft,HIGH);
  // digitalWrite(blueled,HIGH);
  // while(digitalRead(button3)){}
  //OLED_Display();
  // digitalWrite(whiteright,HIGH);
  // delay(1000);
  // digitalWrite(whiteright,LOW);
  // digitalWrite(redled,HIGH);
  // delay(1000);
  // digitalWrite(redled,LOW);
  // digitalWrite(greenled,HIGH);
  // delay(1000);
  // digitalWrite(greenled,LOW);
  // digitalWrite(blueled,HIGH);
  // delay(1000);
  // digitalWrite(blueled,LOW);
  // digitalWrite(whiteleft,HIGH);
  // delay(1000);
  // digitalWrite(whiteleft,LOW);
 
    // digitalWrite(rm1,HIGH);
    // digitalWrite(rm2,LOW);
    // digitalWrite(Rpwm,HIGH);
    // digitalWrite(lm1,HIGH);
    // digitalWrite(lm2,HIGH);
    // digitalWrite(Lpwm,HIGH);
  // distanceFR= Sensor1.readRangeContinuousMillimeters();
  // distanceFL= Sensor2.readRangeContinuousMillimeters();
  // drive((distanceFR-80)*6,(distanceFL-80)*6);

// lineFollow();
// if(n==8){
//   Brake();
//   delay(500);
// }

// start_time = millis();
// Gridupdate_3();
// Cellcolorarray_3();
// CellTRavel_update();
// NumberTheGrid();
// DetectColoredCells();
// Pillval=150;
// CalculateColOrder();
// CalculateRBGSquares();
// current_time=millis();
// Serial.println(current_time);
// for (int a=0;a<3;a++){
//   for (int b=0; b<2 ; b++){
//     Serial.print(MovetoCells[a][b]);
//     Serial.print(" ");
//   }
//   Serial.println();

// }
// Serial.println(CNr);
// Serial.println(CNc);
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
// Serial.print(digitalRead(SLB));
// Serial.print(",");
// Serial.print(digitalRead(SLF));
// Serial.print(",");
// Serial.print(digitalRead(SRF));
// Serial.print(",");
// Serial.print(digitalRead(SRB));
// Serial.print(",");
// Serial.println();
// detectcolour();
// current_time=millis();
// Serial.println(current_time);
//while(1){}
//MoveForward(300,300);
//Serial.print("Left");
// Serial.print(analogRead());
// Serial.print(" , ");
// Serial.println(countright);

// Serial.println();
//delay(50);
// getTOFReading();
// Serial.print("Right");
// Serial.print(countright);
// Serial.println();


//delay(500);
//Brake();
//while(1){}
 
  // put your main code here, to run repeatedly:

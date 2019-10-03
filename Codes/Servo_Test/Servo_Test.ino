#define DOOR_RELEASE_ANGLE 0
#define COIN_ONE 60
#define COIN_TWO 75
#define COIN_THREE 90

#define DOOR_ATTACH_ANGLE 45
#define DOOR_SERVO_PIN 9
#include <Servo.h>
Servo DoorServo;
int state = 0;
void setup() {
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  InitDoorServo();
  delay(2000);
}
void loop() {
  
//  while(Serial.available() > 0) { // Checks whether data is comming from the serial port
////    state = Serial.read(); // Reads the data from the serial port
//  }
  delay(1000);
  TurnCoinOne();
//  while(Serial.available() > 0) { // Checks whether data is comming from the serial port
////    state = Serial.read(); // Reads the data from the serial port
//  }
  delay(1000);
  TurnCoinTwo();
//  while(Serial.available() > 0) { // Checks whether data is comming from the serial port
////    state = Serial.read(); // Reads the data from the serial port
//  }
  delay(1000);
  TurnCoinThree();
//  while(Serial.available() > 0) { // Checks whether data is comming from the serial port
////    state = Serial.read(); // Reads the data from the serial port
//  }
  delay(2000);
  TurnDoorAttach();
  
  
  
}


void InitDoorServo(){
  DoorServo.attach(DOOR_SERVO_PIN);
  DoorServo.write(DOOR_ATTACH_ANGLE);
}


void TurnDoorAttach(){
  for (int pos = COIN_THREE; pos >= DOOR_ATTACH_ANGLE; pos -= 5){
    DoorServo.write(pos);
    delay(20);
  }
}

void TurnCoinOne(){
  for (int pos = DOOR_ATTACH_ANGLE; pos <= COIN_ONE; pos += 1){
    DoorServo.write(pos);
    delay(20);
  }
}
void TurnCoinTwo(){
  for (int pos = COIN_ONE; pos <= COIN_TWO; pos += 1){
    DoorServo.write(pos);
    delay(20);
  }
}

void TurnCoinThree(){
  for (int pos = COIN_TWO; pos <= COIN_THREE; pos += 1){
    DoorServo.write(pos);
    delay(20);
  }
}

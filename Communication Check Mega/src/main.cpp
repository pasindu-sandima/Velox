#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,8);

typedef struct{
  uint16_t A1=10;
  uint16_t A2=20;
  uint16_t A3=30;
  uint16_t A4=40;
  uint16_t A5=50;
  uint16_t A6=60;
} SensorDef;
 SensorDef sensorData;

char data[20]="THIS IS A TEST";
const byte address[6] = {0xff,0xff,0xff,0xff,0xf0};
// uint64_t address = 0xf0ffffffff;

void setup() {
 
  radio.begin();
  radio.setChannel(100);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  Serial.begin(9600);
  while(true){
    if(radio.isChipConnected()){
      Serial.println("Chip Connected");
      break;
    }
  }
  
}

void loop() {

  if(radio.write(&sensorData,sizeof(sensorData))) Serial.println("data transmitted");
  else Serial.println("unsuccssfull");

  delay(2000);

}
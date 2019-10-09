#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,8);
char r_data[30]="";
typedef struct{
  uint16_t A1;
  uint16_t A2;
  uint16_t A3;
  uint16_t A4;
  uint16_t A5;
  uint16_t A6;
} SensorDef;
 SensorDef sensorData;

const byte address[6] = {0xff,0xff,0xff,0xff,0xf0};

void setup() {
  
  Serial.begin(9600);
  
  radio.begin();
  radio.setChannel(100);
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  while(true){
    if(radio.isChipConnected()){
      Serial.println("Chip Connected");
      break;
    }
  }

}

void loop() {
  if(radio.available()){
    Serial.println("radio is avalable");
    radio.read(&sensorData,sizeof(sensorData));
    Serial.println(sensorData.A1); Serial.println("\t");
    Serial.println(sensorData.A2); Serial.println("\t");
    Serial.println(sensorData.A3); Serial.println("\t");
    Serial.println(sensorData.A4); Serial.println("\t");
    Serial.println(sensorData.A5); Serial.println("\t");
    Serial.println(sensorData.A6);// Serial.println("\t");
    Serial.println("ok");
  }

}
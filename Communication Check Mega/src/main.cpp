#include <Arduino.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN


typedef struct{
  uint8_t command;
  uint8_t data;
} commandDef;
commandDef commandPack;

typedef struct{
  uint8_t status=0;
} statusdDef;
statusdDef statusPack;

const byte address[6] = {0xff,0xff,0xff,0xff,0xf0};

#define SEND_value 105
#define CHECK_state 106
#define DONE_assist 107
#define NOT_DONE_assist 108

void send_value();
void check_completion();

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  radio.begin();
  while(!radio.isChipConnected()){}
  Serial.println("Connected");
  radio.setChannel(100);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.enableAckPayload();
  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  Serial.println("Sending");
  send_value();
}



void send_value(){
    int i=1;
    while(i<5){
        // commandPack.command=SEND_value;
        // commandPack.data=108;
        // uint16_t abc = 1233;
        if (radio.write(&"abc",sizeof("abc"))){
            Serial.println("Done Sending");
            break;
        }
        delay(500);
        i++;
    }
    delay(1000);
}


void check_completion(){
    long t1=millis();
    while(abs(millis()-t1)<200000){
        commandPack.command=CHECK_state;
        //Serial.println(statusPack.status);
        if (radio.write(&commandPack,sizeof(commandPack))){
            if (radio.isAckPayloadAvailable()){
               // Serial.println("ack with payload");
                radio.read(&statusPack,sizeof(statusPack));
                
                if(DONE_assist==statusPack.status){
                    Serial.print("feedback_to_continue");
                    break;
                }
            }
        }
    }
}
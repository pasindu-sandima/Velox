RF24 radio(6,7);

void initNRF(){
    radio.begin();
    while(true){
        if(radio.isChipConnected()){
            Serial.println("Chip Connected");
            break;
        }
    }
    radio.setChannel(105);
    radio.setPALevel(RF24_PA_LOW);
    radio.setDataRate(RF24_250KBPS);
    radio.enableAckPayload();
    radio.openWritingPipe(address);
    radio.stopListening();
}


void check_completion(){
    long t1=millis();
    while(abs(millis()-t1)<200000){
        DataPack.Command=checkfeedback;
        if (radio.write(&DataPack,sizeof(DataPack))){
            if (radio.isAckPayloadAvailable()){
                radio.read(&StatusPack,sizeof(StatusPack));
                if(StatusPack.Status==done){
                    Serial.print("feedback_to_continue");
                    Buzz(100);
                    delay(100);
                    Buzz(100);
                    delay(100);
                    Buzz(100);
                    delay(100);
                    break;
                }
            }
        }
    }
}

void indicategreen1(){
    digitalWrite(greenled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=green1;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(greenled,LOW);
}

void indicateblue1(){
    digitalWrite(blueled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=blue1;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(blueled,LOW);
}

void indicatered1(){
    digitalWrite(redled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=red1;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(redled,LOW);
}

void indicatered2(){
    digitalWrite(redled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=red2;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(redled,LOW);
}

void indicatered3(){
    digitalWrite(redled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=red3;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(redled,LOW);
}

void indicateblue2(){
    digitalWrite(blueled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=blue2;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(blueled,LOW);
}

void indicateblue3(){
    digitalWrite(blueled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=blue3;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(blueled,LOW);
}

void indicategreen2(){
    digitalWrite(greenled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=green2;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(greenled,LOW);
}

void indicategreen3(){
    digitalWrite(greenled,HIGH);
    tries=1;
    DataPack.Command=Move;
    DataPack.Position=green3;
    while(tries<5){
        if (radio.write(&DataPack,sizeof(DataPack))){
            Serial.println("Sent Value");
            break;
        }
        delay(500);
        tries++;
    }
    if(tries==5){
        Serial.println("Unsuccesful");
    }
    delay(50);
    digitalWrite(greenled,LOW);
}

void FirstLineIndication(){
    detectcolour();
    if(colour==2){
        indicatered2();
    }
    else if(colour==4){
        indicateblue2();
    }
    else{
        indicategreen2();
    }
}

void SecondLineIndication(){
     detectcolour();
    if(colour==2){
        indicatered3();
    }
    else if(colour==4){
        indicateblue3();
    }
    else{
        indicategreen3();
    }

}

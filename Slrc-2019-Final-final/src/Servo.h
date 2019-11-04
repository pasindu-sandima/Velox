Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void servosetup(){
    pwm.begin();
    pwm.setPWMFreq(60);
    //pwm.setPWM(coinarmservo, 0, DOOR_ATTACH_ANGLE);
    pwm.setPWM(AssArm, 0, ASSservodown);
    pwm.setPWM(magnetservo,0,magnetservorelease);
}
// void CoinArm15(){
//     if (coinnum==1){
//         for (uint16_t pulselen = coinservonormal; pulselen < coinservo1; pulselen++) {
//         pwm.setPWM(coinarmservo, 0, pulselen);
//         delay(1);
//         }
//     }
//     if(coinnum==2){
//         for (uint16_t pulselen = coinservo1; pulselen < coinservo2; pulselen++) {
//         pwm.setPWM(coinarmservo, 0, pulselen);
//         delay(1);
//         }
//     }
//     if (coinnum==3){
//         for (uint16_t pulselen = coinservo2; pulselen < coinservo3; pulselen++) {
//         pwm.setPWM(coinarmservo, 0, pulselen);
//         delay(1);
//         }
//     }   
// }
void MagnetNormal(){
    for (uint16_t pulselen = magnetservonormal; pulselen > magnetservorelease; pulselen--){
        pwm.setPWM(magnetservo, 0, pulselen);
        delay(5);
    }
}
void MagnetRelease(){
    for (uint16_t pulselen = magnetservorelease; pulselen < magnetservonormal; pulselen++){
        pwm.setPWM(magnetservo, 0, pulselen);
        delay(5);
    }
}

void AssARMdown(){
    for (uint16_t pulselen = ASSservodown; pulselen < ASSservoup; pulselen++){
        pwm.setPWM(AssArm, 0, pulselen);
        delay(5);
    }
}
void AssARMup(){
    for (uint16_t pulselen = ASSservoup; pulselen >ASSservodown; pulselen--){
        pwm.setPWM(AssArm, 0, pulselen);
        delay(5);
    }

}
void TurnDoorAttach(){
  for (int pos = COIN_THREE; pos >= DOOR_ATTACH_ANGLE; pos -= 5){
    pwm.setPWM(coinarmservo, 0, pos);
    delay(15);
  }
}

void TurnCoinOne(){
  for (int pos = DOOR_ATTACH_ANGLE; pos <= COIN_ONE; pos += 1){
    pwm.setPWM(coinarmservo, 0, pos);
    delay(15);
  }
}
void TurnCoinTwo(){
  for (int pos = COIN_ONE; pos <= COIN_TWO; pos += 1){
    pwm.setPWM(coinarmservo, 0, pos);
    delay(15);
  }
}

void TurnCoinThree(){
  for (int pos = COIN_TWO; pos <= COIN_THREE; pos += 1){
    pwm.setPWM(coinarmservo, 0, pos);
    delay(15);
  }
}




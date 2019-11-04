
void lineFollow(){
    n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

    if (analogRead(S1)< white_range) {
        n++;
        sum-=w4;
        lineout=-1;            
    }
    if (analogRead(S2)< white_range) {
        n++;
        sum-=w3;   
        lineout=-1;            
    }
    if (analogRead(S3)< white_range) {
        n++;
        sum-=w2;   
        lineout=-1;            
    }
    if (analogRead(S6)< white_range) {
        n++;
        lineout=1;            
        sum+=w2;            
    }
    if (analogRead(S7)< white_range) {
        n++;
        lineout=1;            
        sum+=w3;            
    }
    if (analogRead(S8)< white_range) {
        n++;
        lineout=1;            
        sum+=w4;            
    }
    if (analogRead(S4)< white_range) {
        n++;
        lineout=0;            
        sum-=w1;            
    }
    if (analogRead(S5)< white_range) {
        n++;
        lineout=0;            
        sum+=w1;            
    }
    if(n!=0){
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(lm2,LOW);
        error = sum/n;
        adj = Kp*error + Kd*(error-last_error);
        last_error = error;
        if (adj>0) {      
            Lspeed += adj/w6;
            Rspeed -= adj/w5;
        }
        else{
            Rspeed -= adj/w6;
            Lspeed += adj/w5;
        }
        if (Rspeed>900){
            Rspeed = 900;
        }
        if (Lspeed>900){
            Lspeed = 900;
        }
        if (Rspeed<0){
            digitalWrite(rm2,HIGH);
            digitalWrite(rm1,LOW);
            Rspeed = - Rspeed;
        }
        if (Lspeed<0){
            digitalWrite(lm2,HIGH);
            digitalWrite(lm1,LOW);
            Lspeed = - Lspeed;
            }
        analogWrite(Rpwm, Rspeed);
        analogWrite(Lpwm, Lspeed);
    }
    // else{
    //    Brake();
    // }
}
void detectcolour(){
    //Sets the frequency to 20%.... Set both to high for 100%
    //delay(1200);//time calculation
    digitalWrite(SC0,HIGH);
    digitalWrite(SC1,LOW);
    red=0;
    green=0;
    blue=0;
    digitalWrite(redled,LOW);
    digitalWrite(blueled,LOW);
    digitalWrite(greenled,LOW);
    digitalWrite(whiteleft,LOW);
    digitalWrite(whiteright,LOW);

    
    for (int detect=0;detect<3;detect++){
        //detecting red 
        digitalWrite(SC2,LOW);
        digitalWrite(SC3,LOW);
        // delay(100);
        red = pulseIn(sensorOut, LOW);   
        delay(40);
        //detecting green 
        digitalWrite(SC2,HIGH);
        digitalWrite(SC3,HIGH);
        // delay(100);
        green = pulseIn(sensorOut, LOW); 
        delay(40);
        //detecting blue
        digitalWrite(SC2,LOW);
        digitalWrite(SC3,HIGH);
        // delay(100);
        blue = pulseIn(sensorOut, LOW);
        delay(40);
    }
   

    // Serial.print(red);
    // Serial.print("  ,  ");
    // Serial.print(blue);
    // Serial.print("   ,  ");
    // Serial.print(green); 
    // Serial.println(" ");
    if ((red+green+blue)>650&&(green>210)){
        colour=0;
    }
    else{
        if(red<100 && blue<100 && green<100){
            digitalWrite(whiteleft,HIGH);
            digitalWrite(whiteright,HIGH);
            colour=0;
            //Serial.println("White");
        }
        else{
            if((red<blue)&&(red<green)){
                colour=2;
                digitalWrite(redled,HIGH);
            }
            else if((blue<red)&&(blue<120)){
                colour=4;
                digitalWrite(blueled,HIGH);
            }
            else{
                colour=3;
                digitalWrite(greenled,HIGH);

        }
        
    }
}
}

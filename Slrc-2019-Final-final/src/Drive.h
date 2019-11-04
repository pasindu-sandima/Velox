
void MoveOneNode(){
    while(true){
        if((digitalRead(SLF)==HIGH)||(digitalRead(SRF)==HIGH)){
            break;
        }
        lineFollow();
    }
    //digitalWrite(buzzer,HIGH);
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SRB)==HIGH)){
            break;
        }
        if(countright<3000){
            rspeed=500-countright/8;
            lspeed=500-countright/8;
        }
        else{
            rspeed=125;
            lspeed=125;
        }
        lineFollow();

    }
    countright=0;
    while(true){
        if(countright>250){
            break;
        }
        lineFollow();

    }
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    Brake();
    //digitalWrite(buzzer,LOW);


}

void GoToNode(){
    int row=CNr-DNr;
    int col=CNc-DNc;
    if (row>0){
        Turn(1);
    }
    else if(row<0){
        Turn(3);
    }
    // Brake();
    // delay(50);
    for(int s=0;s<abs(row);s++){
        MoveOneNode();
       // Buzz(150);
    }
    Brake();
    //Buzz(150);
    delay(150);
    if (col>0){
        Turn(2);
    }
    else if(col<0){
        Turn(0);
    }
    // Brake();
    // delay(50);
    for(int r=0;r<abs(col);r++){
        MoveOneNode();
        // Brake();
        // digitalWrite(buzzer,HIGH);
        // delay(100);
        // digitalWrite(buzzer,LOW);
    }
    Brake();
    delay(50);
    Turn(2);
    digitalWrite(blueled,LOW);

}
void TurnLeft(){
    Brake();
    delay(200);
    //delay(1300);//time calculation
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<25){
        countright=0;
        while(countright<51){}
        phasecount++;
    }  
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
    detachInterrupt(digitalPinToInterrupt(2));
    if (Face==0){
        Face=1;
    }
    else if (Face==1){
        Face=2;
    }
    else if (Face==2){
        Face=3;
    }
    else {
        Face=0;
    }
}
void TurnRight(){
    Brake();
    delay(200);//time calculation
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(18),leftcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(19),leftcount,CHANGE);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<25){
        countleft=0;
        while(countleft<52){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(18));
    detachInterrupt(digitalPinToInterrupt(19));
    if (Face==0){
        Face=3;
    }
    else if (Face==1){
        Face=0;
    }
    else if (Face==2){
        Face=1;
    }
    else{
        Face=2;
    }
}
void Turn180(){
    Brake();
    delay(200);
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE); //encoder
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,505);
    analogWrite(Lpwm,505);
    while(phasecount<57){
        countright=0;
        while(countright<49){}
        phasecount++;
    }
    // while(countright<500){
    //     analogWrite(Rpwm,200+countright);
    //     analogWrite(Lpwm,200+countright);
    // }
    // while(countright<2200){
    //     analogWrite(Rpwm,700);
    //     analogWrite(Lpwm,700);
    // } 
    // while(countright<2680){
    //     analogWrite(Rpwm,2850-countright);
    //     analogWrite(Lpwm,2850-countright);
    // }    
    Brake();
    // leftjunction=false;
    // rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
    detachInterrupt(digitalPinToInterrupt(2));
    if (Face==0){
        Face=2;
    }
    else if (Face==1){
        Face=3;
    }
    else if (Face==2){
        Face=0;
    }
    else{
        Face=1;
    }
}
void countForward(int count){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoders
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    rcount = countright+count;
    condition = true;
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,300);
    analogWrite(Lpwm,300);
    while(condition){
        if (rcount<countright) {
            condition=false;
        }  
    }
    Brake();
    detachInterrupt(digitalPinToInterrupt(3));
    detachInterrupt(digitalPinToInterrupt(2));
}

void MoveForward(int rspeed,int lspeed){
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(Rpwm,rspeed);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Lpwm,lspeed);

}
void drive(int rspeed,int lspeed){
    if(rspeed>0){
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
    }
    else{
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,HIGH);
        rspeed=-rspeed;
    }
    if(lspeed>0){
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
    }
    else{
        digitalWrite(lm1,LOW);
        digitalWrite(lm2,HIGH);
        lspeed=-lspeed;
    }
    
    analogWrite(Rpwm,rspeed);
    analogWrite(Lpwm,lspeed);

}
void Brake(){
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,HIGH);
    digitalWrite(Rpwm,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,HIGH);
    digitalWrite(Lpwm,HIGH);
}
void Turn(int dir){
    if(Face!=dir){
        if (Face==0){
            if(dir==1){
                TurnLeft();
            }
            else if (dir==2){
                Turn180();
            }
            else if(dir==3){
                TurnRight();
            }
        }
        else if(Face==1){
            if(dir==2){
                TurnLeft();
            }
            else if (dir==3){
                Turn180();
            }
            else if(dir==0){
                TurnRight();
            }    
        }
        else if(Face==2){
            if(dir==3){
                TurnLeft();
            }
            else if (dir==0){
                Turn180();
            }
            else if(dir==1){
                TurnRight();
            }    
        }
        else if(Face==3){
            if(dir==0){
                TurnLeft();
            }
            else if (dir==1){
                Turn180();
            }
            else if(dir==2){
                TurnRight();
            }    
        }

    }
    delay(200);
    Face=dir;
}

void Decelarate(int count,int presSpeed){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
}

void TurnRight45(){
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(18),leftcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(19),leftcount,CHANGE);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<12){
        countleft=0;
        while(countleft<50){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(18));
    detachInterrupt(digitalPinToInterrupt(19));
}

void TurnLeft45(){
    Brake();
    delay(200);
    //delay(1300);//time calculation
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<12){
        countright=0;
        while(countright<51){}
        phasecount++;
    }  
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
    detachInterrupt(digitalPinToInterrupt(2));
   
}

void Reverse(){
    delay(1300);//time calculation
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(18),leftcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(19),leftcount,CHANGE);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,200);
    analogWrite(Lpwm,200);
    while(phasecount<30){
        countleft=0;
        while(countleft<50){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(18));
    detachInterrupt(digitalPinToInterrupt(19));
}

void CorrectPosition(){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SRB)==HIGH)){
            break;
        }
        if(countright<3000){
            rspeed=300-countright/14;
            lspeed=300-countright/14;
        }
        else{
            rspeed=100;
            lspeed=100;
        }
        lineFollow();

    }
    countright=0;
    while(true){
        if(countright>250){
            break;
        }
        lineFollow();

    }
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    Brake();
}

void CorrectPosition500(){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SRB)==HIGH)){
            break;
        }
        if(countright<3000){
            rspeed=500-countright/8;
            lspeed=500-countright/8;
        }
        else{
            rspeed=125;
            lspeed=125;
        }
        lineFollow();

    }
    countright=0;
    while(true){
        if(countright>250){
            break;
        }
        lineFollow();

    }
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    Brake();
}

void TurnRightSlow(){
    Brake();
    delay(200);//time calculation
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(18),leftcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(19),leftcount,CHANGE);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,200);
    analogWrite(Lpwm,200);
    while(phasecount<27){
        countleft=0;
        while(countleft<51){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(18));
    detachInterrupt(digitalPinToInterrupt(19));
    if (Face==0){
        Face=3;
    }
    else if (Face==1){
        Face=0;
    }
    else if (Face==2){
        Face=1;
    }
    else{
        Face=2;
    }
}

void TurnLeftSlow(){
    Brake();
    delay(200);//time calculation
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,200);
    analogWrite(Lpwm,200);
    while(phasecount<28){
        countright=0;
        while(countright<51){}
        phasecount++;
    }
    Brake();
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    if (Face==0){
        Face=1;
    }
    else if (Face==1){
        Face=2;
    }
    else if (Face==2){
        Face=3;
    }
    else {
        Face=0;
    }
}

void encoderback(){
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(18),leftcount,CHANGE); //encoder
    attachInterrupt(digitalPinToInterrupt(19),leftcount,CHANGE);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,200);
    analogWrite(Lpwm,200);
    while(phasecount<10){
        countleft=0;
        while(countleft<50){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(18));
    detachInterrupt(digitalPinToInterrupt(19));
}

void CorrectPosition1(){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SRB)==HIGH)){
            break;
        }
        if(countright<3000){
            rspeed=300-countright/14;
            lspeed=300-countright/14;
        }
        else{
            rspeed=100;
            lspeed=100;
        }
        lineFollow();

    }
    countright=0;
    while(true){
        if(countright>400){
            break;
        }
        lineFollow();

    }
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    Brake();
}







void MoveOneNode(){
    delay(500);//time calculation
}

void GoToNode(){
    int row=CNr-DNr;
    int col=CNc-DNc-1;
    for(int s=0;s>row;s++){
        if (row>0){
            Turn(1);
            MoveOneNode();
        }
        else if(row<0){
            Turn(3);
            MoveOneNode;
        }  
    }
    for(int r=0;r>col;r++){
        if (col>0){
            Turn(2);
            MoveOneNode();
        }
        else if(col<0){
            Turn(0);
            MoveOneNode;
        }    
    }
    Turn(0);
}
void TurnLeft(){
    delay(1300);//time calculation
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<16){
        countright=0;
        while(countright<49){}
        phasecount++;
    }  
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
}
void TurnRight(){
    delay(1300);//time calculation
    phasecount=0;
    countleft=0;
    attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoder
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<15){
        countleft=0;
        while(countleft<50){}
        phasecount++;
    }
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(2));
}
void Turn180(){
    phasecount=0;
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    analogWrite(Rpwm,390);
    analogWrite(Lpwm,400);
    while(phasecount<34){
        countright=0;
        while(countright<49){}
        phasecount++;
    }  
    Brake();
    leftjunction=false;
    rightjunction=false;
    detachInterrupt(digitalPinToInterrupt(3));
}
void countForward(int count){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoders
    rcount = countright+count;
    condition = true;
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(Rpwm,312);
    analogWrite(Lpwm,340);
    while(condition){
        if (rcount<countright) {
            condition=false;
        }  
    }
    Brake();
    detachInterrupt(digitalPinToInterrupt(3));
}
void CheckForPillars(){
    if ((distanceR<140)&&(distanceL<140)){
        LRB=3;
    }
    else if(distanceR<140){
        LRB=2;
    }
    else if (distanceL<140){
        LRB=1;
    }
}
void MoveForward(int rspeed,int lspeed){
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(Rpwm,rspeed);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
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
    Face=dir;
}
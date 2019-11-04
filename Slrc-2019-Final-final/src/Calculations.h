void CalculateColOrder(){
    
    Redval=(NumGridCell[Red[4]][Red[5]])+(NumGridCell[Red[2]][Red[3]]*NumGridCell[Red[2]][Red[3]])+(NumGridCell[Red[0]][Red[1]]*NumGridCell[Red[0]][Red[1]])*NumGridCell[Red[0]][Red[1]];
    Blueval=(NumGridCell[Blue[4]][Blue[5]])+(NumGridCell[Blue[2]][Blue[3]]*NumGridCell[Blue[2]][Blue[3]])+(NumGridCell[Blue[0]][Blue[1]]*NumGridCell[Blue[0]][Blue[1]]*NumGridCell[Blue[0]][Blue[1]]);
    Greenval=(NumGridCell[Green[4]][Green[5]])+(NumGridCell[Green[2]][Green[3]]*NumGridCell[Green[2]][Green[3]])+(NumGridCell[Green[0]][Green[1]]*NumGridCell[Green[0]][Green[1]]*NumGridCell[Green[0]][Green[1]]);
    //Serial.println(Redval);
    //Serial.println(Greenval);
    //Serial.println(Blueval);
    if (Blueval>Redval){
        //Serial.print("yes");
        if (Redval>Greenval){
            Order[0]=3;//G
            Order[1]=2;//r
            Order[2]=4;//b
        }
        else if (Greenval>Blueval)
        {
          //Serial.print("yes i right");  
            Order[0]=2;//r
            Order[1]=4;//b
            Order[2]=3;//g
            
        }
        else
        {
            //cout<< ;
            Order[0]=2;//r
            Order[1]=3;//g
            Order[2]=4;//b
            
        }
    }
    else{
        if(Greenval>Redval){
            Order[0]=4;//b
            Order[1]=2;//r
            Order[2]=3;//g
        }
        else if(Greenval<Blueval){
            Order[0]=3;//g
            Order[1]=4;//b
            Order[2]=2;//r
        }
        else{
            Order[0]=4;//b
            Order[1]=3;//g
            Order[2]=2;//r
        }
    } 
}

void GenPillVal(){
    pillposval+=10;
    CheckForPillars();
    Pillval+=LRB*pillposval;   
}

void CalculateRBGSquares(){
    for(int j=0;j<3;j++){
        if (Order[j]==2){
            if (Pillval>99 && Pillval<167){
                MovetoCells[j][0]=Red[0];
                MovetoCells[j][1]=Red[1];
            }
            else if(Pillval>166 && Pillval<234){
                MovetoCells[j][0]=Red[2];
                MovetoCells[j][1]=Red[3];
            }
            else{
                MovetoCells[j][0]=Red[4];
                MovetoCells[j][1]=Red[5];
            }
        }
        else if(Order[j]==3){
            if (thirdFromEnd[Pillval-1]>-1 && thirdFromEnd[Pillval-1]<3){
                MovetoCells[j][0]=Green[0];
                MovetoCells[j][1]=Green[1];
            }
            else if(thirdFromEnd[Pillval-1]>2 && thirdFromEnd[Pillval-1]<7){
                MovetoCells[j][0]=Green[2];
                MovetoCells[j][1]=Green[3];
            }
            else{
                MovetoCells[j][0]=Green[4];
                MovetoCells[j][1]=Green[5];
            }
        }
        else{
            if (thirdfromfront[Pillval-1]>-1 && thirdfromfront[Pillval-1]<3){
                MovetoCells[j][0]=Blue[0];
                MovetoCells[j][1]=Blue[1];
            }
            else if(thirdfromfront[Pillval-1]>2 && thirdfromfront[Pillval-1]<7){
                MovetoCells[j][0]=Blue[2];
                MovetoCells[j][1]=Blue[3];
            }
            else{
                MovetoCells[j][0]=Blue[4];
                MovetoCells[j][1]=Blue[5];
            }
        }
    }
}
void CheckForPillars(){
    delay(30);
    measure(); 
    // Serial2.print(distanceL);
    // Serial2.print(",");
    // Serial2.println(distanceR); 
    if ((distanceR<250)&&(distanceL<250)){
        digitalWrite(whiteleft,HIGH);
        digitalWrite(whiteright,HIGH);
        LRB=3;
        Buzz(50);
        digitalWrite(whiteleft,LOW);
        digitalWrite(whiteright,LOW);
        
    }
    else if(distanceR<250){
        digitalWrite(whiteright,HIGH);
        LRB=2;
        Buzz(50);
        digitalWrite(whiteright,LOW);
    
    }
    else if (distanceL<250){
        digitalWrite(whiteleft,HIGH);
        LRB=1;
        Buzz(50);
        digitalWrite(whiteleft,LOW);
    }
}

void Pillars(){
    rspeed=500;
    lspeed=500;
    for(int i=0;i<4;i++){
        while(true){
            if((digitalRead(SLF)==HIGH)&&(digitalRead(SRF)==HIGH)){
                break;
            }
            lineFollow();
        }
        delay(10);
        Brake();

        GenPillVal();
        //delay(50);
        //delay(1000);
        while(true){
            if((digitalRead(SLF)==LOW)&&(digitalRead(SRF)==LOW)){
                break;
            }
            lineFollow();
        }
        

    }
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;

        }
        lineFollow();
        
    }
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
    Brake();
    stopTOF();
    
    
}
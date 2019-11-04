// #include <iostream>
// using namespace std;
// #include<grid.h>
void Buzz(uint16_t time){
    digitalWrite(buzzer,HIGH);
    delay(time);
    digitalWrite(buzzer,LOW);

}

// void CellColorArray(int color[],int CellColor[8][8],int CellTravelColor[64]){
//     //GridColorUpdate(ccolor);
//     int HLC=15;
//     int LLC=0;
//     for (int i=0;i<8;i++){
//         for(int j=0;j<8;j++){
//             if (color[LLC+j]==color[HLC-j]){
//                 CellTravelColor[i*8+j]=color[LLC+j];
//                 if ((i==1)||(i==3)||(i==5)||(i==7)){
//                     CellColor[i][7-j]=color[LLC+j];
//                    //cout << i << " ";
//                 }
//                 else{
//                     //cout << i << "  ";
//                     CellColor[i][j]=color[LLC+j];
//                 }
//             }
//             else if(color[LLC+j]!=color[HLC-j]){
//                 CellTravelColor[i*8+j]=0;
//                 if ((i==1)||(i==3)||(i==5)||(i==7)){
//                     CellColor[i][7-j]=0;
//                     //cout << i << " ";
//                 }
//                 else{
//                     //cout << i << " ";
//                     CellColor[i][j]=0;
//                 }
//             }
//         }
//         HLC+=8;
//         LLC+=8;
//         cout << endl;
//     }
// }

// int main(){
//     int ccolor[72]={0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,3,0,0,4,0,3,0,2,0,0,4,0,0,0,0,0,0,0,4,0,2,0,2,0,0,2,0,4,0,2,0,0,2,0,0,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,3,0,0,0,0};
//     int CellColor[8][8];
//     int CellTravelColor[64];
//     CellColorArray(ccolor,CellColor,CellTravelColor);
//     for (int i = 0; i < 9; i++) 
// { 
//   for (int j = 0; j < 8; j++) 
//   { 
//       cout << ccolor[i*8+j] << " "; 
//   } 
     
//   // Newline for new row 
//   cout << endl; 
// }

// cout << endl; 
// cout << endl; 
// cout << endl; 

//   for (int i = 0; i < 8; i++) 
// { 
//   for (int j = 0; j < 8; j++) 
//   { 
//       cout << CellColor[i][j] << " "; 
//   } 
     
//   // Newline for new row 
//   cout << endl; 
// }
// cout << endl; 
// cout << endl; 
// cout << endl;

// for (int i = 0; i < 8; i++) 
// { 
//   for (int j = 0; j < 8; j++) 
//   { 
//       cout << CellTravelColor[i*8+j] << " "; 
//   } 
     
//   // Newline for new row 
//   cout << endl; 
// }
// }

// void NumberTheGrid(int CellTravelColor[64],int NumTravelGrid[64],int NumGridCell[8][8]){
//     int n=1;
//     int PCV=0;
//     for (int i = 0; i < 8; i++){
//         for (int j = 0; j < 8; j++){
//             NumTravelGrid[i*8+j]=(PCV+n);
//             if ((i==1)||(i==3)||(i==5)||(i==7)){
//                 NumGridCell[i][7-j]=(PCV+n);
//             }
//             else{
//             NumGridCell[i][j]=(PCV+n); 
//             }
//             PCV=NumTravelGrid[i*8+j];
            
//             if (CellTravelColor[i*8+j]!=0){
//                 n=CellTravelColor[i*8+j];
//             }
//         }
//     }
   
// }

// void Gridupdate_3check(){
//     //Serial.println("done");
//     // TurnRight();
//     // Brake();
//     // delay(100);
//     // MoveOneNode();
//     // Brake();
//     // delay(100);
//     // TurnLeft();
//     // Brake();
//     // delay(100);
//     int ccheck=0;
//     int numcolcells=0;
//     int mark=0;
//     for (int i=0;i<4;i++){
//         for (int j=0;j<8;j++){
//             if (numcolcells==9){
//                 color_3[i*8+j]=0;
//                 mark+=1;
//                 if(mark==1){
//                     CNr=i*2+1;
//                     if(i%2==1){
//                         CNc=8-(j-1);
//                     }
//                     else{
//                         CNc=j-1;
//                     }
//                 }
//             }
            
//             else if (ccheck!=0){
//                 //Serial.println(ccolor_3[i*8+j]);
//                 ccheck=0;
//                 color_3[i*8+j]=0;
//                 //MoveOneNode();
                
//             }
//             else{
//                // detectcolour();
                
//                 color_3[i*8+j]=ccolor_3[i*8+j];
//                 //Serial.println(ccolor_3[i*8+j]);
//                 if (color_3[i*8+j]!=0){
//                     ccheck=1;
//                     if ((i==0)||(i==2)){
//                         // delay(3200);
//                         // TurnLeft();
//                         // Brake();
//                         // delay(100);
//                         // detectcolour();
//                         array_3[numcolcells]=array_3dummy[numcolcells];
//                         // TurnRight();
//                         // Brake();
//                         // delay(100);

//                     }
//                     else{
//                         // TurnRight();
//                         // detectcolour();
//                          array_3[numcolcells]=array_3dummy[numcolcells];
//                         // TurnRight();
//                         // Brake();
//                         // delay(100); 
//                     }
//                     numcolcells+=1;    
//                 }
//                 if(numcolcells!=9){
//                     // MoveOneNode();
//                     // Brake();
//                     // delay(100);
//                 }    
//             }
//         }
//         // Buzz(150);
//         if(numcolcells!=9){
//             if ((i%2)==1){
           
//             //  TurnLeft();
//             //  Brake();
//             //  delay(100);
//             //  MoveOneNode();
//             //  MoveOneNode();
//             //  TurnLeft();  
//             // Brake();
//             // delay(100); 
//             }
//             else{
             
//             //  TurnRight();
//             //  Brake();
//             // delay(100);
//             //  MoveOneNode();
//             //  MoveOneNode();
//             //  TurnRight();
//             //  Brake();
//             // delay(100);
//             }  
//         } 
//     }
// }
// void DetectColoredCellscheck(){
//     int r=0;
//     int g=0;
//     int b=0;
//     int q=0;
//     for (int p=0;p<8;p++){
//         for (int u=0;u<8;u++){
//             if ((p==1)||(p==3)||(p==5)||(p==7)){
//                 q=7-u;
//             }
//             else{
//                 q=u;
//             }
//             if (CellTravelColor[p*8+q]!=0){
//                 if (CellTravelColor[p*8+q]==2){
//                     Red[r]=p;
//                     Red[r+1]=q;
//                     r+=2;   
//                 }
//                 else if(CellTravelColor[p*8+q]==3){
//                     Green[g]=p;
//                     Green[g+1]=q;
//                     g+=2;
//                 }
//                 else{
//                     Blue[b]=p;
//                     Blue[b+1]=q;
//                     b+=2;
//                 }
//             }        
//         }
//     }
// }
// 1,5
// 3,4
// 3,6
void GridSolve(){
    Gridupdate_4();
    // OLED_Display(String(CNr)+","+String(CNc)+",            "+String(Face));
  Cellcolorarray_3();
  CellTRavel_update();
  NumberTheGrid();
  DetectColoredCells();
  Buzz(150);
  delay(400);
    //   digitalWrite(redled,HIGH);
    //   OLED_Display(String(Red[0])+","+String(Red[1])+",   "+String(Red[2])+","+String(Red[3])+",   "+String(Red[4])+","+String(Red[5]));
    //   delay(1000);
    //   digitalWrite(blueled,HIGH);
    //   OLED_Display(String(Blue[0])+","+String(Blue[1])+",   "+String(Blue[2])+","+String(Blue[3])+",   "+String(Blue[4])+","+String(Blue[5]));
    //   delay(1000);
    //   digitalWrite(greenled,HIGH);
    //   OLED_Display(String(Green[0])+","+String(Green[1])+",   "+String(Green[2])+","+String(Green[3])+",   "+String(Green[4])+","+String(Green[5]));
    //   delay(1000);
    //   Buzz(150);
    //   delay(400);
  CalculateColOrder();
    //   Pillval=180;
  CalculateRBGSquares();
  //OLED_Display(String(MovetoCells[0][0])+","+String(MovetoCells[0][1])+",         "+String(MovetoCells[1][0])+","+String(MovetoCells[1][1])+",         "+String(MovetoCells[2][0])+","+String(MovetoCells[2][1]));
  delay(100);
  DetachCoins();
  Buzz(100);
  delay(50);
  Buzz(100);
  DNr=8;
  DNc=0;
  GoToNode();
}

void Task(){
    rspeed=300;
    lspeed=300;
    while(true){
        lineFollow();
        if(n!=8){
            break;
        }
    }
    while(true){
        if (digitalRead(SRB)==LOW){
            break;
        }
        lineFollow();
    }
    while(true){
        if (digitalRead(SRF)==HIGH){
            delay(50);
            break;
        }
        lineFollow();
    }
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition();
    Brake();
    delay(100);
    TurnRightSlow();
    Brake();
    delay(100);
    while(true){
        lineFollow(); 
        if (n==8){
            Brake();
            break;
        }
          
    }
    encoderback();
    AssARMdown();
    delay(200);
    MagnetRelease();
    Reverse();
    MagnetNormal();
    AssARMup();
    Turn180();
    Reverse();
    Brake();
    delay(150);
    rspeed=500;
    lspeed=500;
    while(true){
        if (digitalRead(SLF)==HIGH){
            break;
        }
        
        lineFollow();   
    }
    //CorrectPosition();
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
    Brake();
    TurnRight();
    delay(150);
    Pillars();
    delay(100);
    GridSolve();
    rspeed=800;
    lspeed=800;
    while(true){
        lineFollow();
        if (n==8){
            break;
        }
        if(n==0){
            Brake();
            while(true){}

        }
    }
    countForward(1800); 
}


void uptoPillars(){
    rspeed=300;
    lspeed=300;
    while(true){
        lineFollow();
        if(n!=8){
            break;
        }
    }
    while(true){
        if (digitalRead(SRB)==LOW){
            break;
        }
        lineFollow();
    }
    while(true){
        if (digitalRead(SRB)==HIGH){
            delay(50);
            break;
        }
        lineFollow();
    }
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition();
    Brake();
    delay(100);
    TurnRightSlow();
    Brake();
    delay(100);
    while(true){
        lineFollow(); 
        if (n==8){
            Brake();
            break;
        }
          
    }
    encoderback();
    AssARMdown();
    delay(200);
    MagnetRelease();
    drive(-300,-300);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SLB)==HIGH)){
            Brake();
            break;
        }
    }
    CorrectPosition();
    Brake();
    MagnetNormal();
    delay(20);
    AssARMup();
    delay(20);
    TurnLeft();
    delay(200);
}

void Task2(){
    uptoPillars();
    Pillars();
    delay(150);
    GridSolve();
    ToArea1();
    EnteringArea1();
    LeavingArea1();
    EnterArea2();
    FinishTask();


}

void AccStraight(){
    countright=0;
    attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE);
    rspeed=300;lspeed=300;
    while(true){
        lineFollow();
        rspeed=300+countright/4;
        lspeed=300+countright/4;
        if(countright>2000){
            break;
        }    
    }
    rspeed=800;
    lspeed=800;
    while(true){
        if(countright>14000){
            break;
        }
        lineFollow();
    }
    countright=0;
    while(true){
        if(digitalRead(SRF)==HIGH||(digitalRead(SLF)==HIGH)){
            break;
        }
        if(rspeed>500){
            rspeed=800-countright/10;
            lspeed=800-countright/10;
        }
        lineFollow();
    }
    countright=0;
    while(true){
        if(digitalRead(SRB)==HIGH||(digitalRead(SLB)==HIGH)){
            break;
        }
        if(rspeed>150){
            rspeed=500-countright;
            lspeed=rspeed;
            drive(rspeed,lspeed);
        }        
    }
    countright=0;
    while (true){
        if(countright>250){
            break;
        }
    }
    Brake();
    detachInterrupt(2);
    detachInterrupt(3);

}

void ToArea1(){
    Kp=10;
    Kd=20;
    AccStraight();
    delay(150);
    TurnRight();
    delay(150);
    AccStraight();
    delay(150);
    Kd=115; Kp=15;
    TurnRight();
    delay(150);
    rspeed=500;
    lspeed=500;
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition();
    Brake();
    delay(100);
    TurnRight();
    Brake();
    delay(100);
}

void EnteringArea1(){
    AssARMdown();
    delay(100);
    rspeed=400;
    lspeed=400;
    while(true){
        lineFollow(); 
        if (n==8){
            Brake();
            break;
        }
            
    }
    delay(100);
    AssARMup();
    drive(-300,-300);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SLB)==HIGH)){
            Brake();
            break;
        }
    }
    delay(100);
    CorrectPosition();
    Brake();
    delay(100);
    TurnRightSlow();
}

void LeavingArea1(){
    rspeed=300;
    lspeed=300;
    while(true){
        if (digitalRead(SLF)==HIGH){
            break;
        }
        lineFollow();
    }

    CorrectPosition1();
    Brake();
    delay(100);
    TurnLeftSlow();
    delay(100);
    rspeed=300;
    lspeed=300;
    while(true){
        if (digitalRead(SLB)==HIGH){
            break;
        }
        lineFollow();
    }

    while(true){
        if (digitalRead(SLF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition();
    Brake();
    delay(100);
    TurnLeftSlow();
    delay(100);
}

void EnterArea2(){
    rspeed=300;
  lspeed=300;
  while(true){
      if (digitalRead(SLF)==HIGH){
          break;
      }
      lineFollow();
  }
  CorrectPosition1();
  Brake();
  delay(100);
  TurnLeftSlow();
  delay(100);
  countright=0;
  attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
  attachInterrupt(digitalPinToInterrupt(2),rightcount,CHANGE);
  while(true){
    lineFollow();
    if(countright>1000){
      Brake();
      break;
    }
  }
    AssARMdown();
    delay(100);
    MagnetRelease();
    delay(100);
    drive(-300,-300);
    while(true){
        if((digitalRead(SLB)==HIGH)||(digitalRead(SLB)==HIGH)){
            Brake();
            break;
        }
    }
    delay(100);
    CorrectPosition();
    Brake();
    delay(100);
    TurnLeftSlow();
    MagnetNormal();
    AssARMup();
    indicatered2();
}

void FinishTask(){
    rspeed=500;lspeed=500;
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition500();
    delay(100);
    TurnRight();
    rspeed=500;lspeed=500;
    while(true){
        if (digitalRead(SRF)==HIGH){
            break;
        }
        lineFollow();
    }
    CorrectPosition500();
    delay(100);
    TurnRight();
    delay(100);
    FirstLineIndication();
    MoveOneNode();
    SecondLineIndication();
    MoveOneNode();
    countForward(300);
    //countForward(1800);
    Brake();
}
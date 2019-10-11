
void GridColorUpdate(){
    //int ccheck=0;
    for (int i=0;i<9;i++){
        for (int j=0;j<8;j++){
            //detectcolour();
            delay(1600);
            color[i*8+j]=ccolor[i*8+j];

            delay(500);//MoveOneNode();
            //Serial.println(time);
        }
        if ((i/2)==1){
            delay(2500);
            // TurnLeft();
            // MoveOneNode();
            // TurnLeft();   
        }
        else{
            delay(2500);
            // TurnRight();
            // MoveOneNode();
            // TurnRight();
        }
        
    }
}

void CellColorArray(){
    //GridColorUpdate();
    int HLC=15;//High level cell
    int LLC=0;//Low level cell
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (color[LLC+j]==color[HLC-j]){
                CellTravelColor[i*8+j]=color[LLC+j];
                if ((i==1)||(i==3)||(i==5)||(i==7)){
                    CellColor[i][7-j]=color[LLC+j]; 
                }
                else{  
                    CellColor[i][j]=color[LLC+j];
                }
                color[HLC-j]=0;
            }
            else if(color[LLC+j]!=color[HLC-j]){
                CellTravelColor[i*8+j]=0;
                if ((i==1)||(i==3)||(i==5)||(i==7)){
                    CellColor[i][7-j]=0;   
                }
                else{
                    CellColor[i][j]=0;
                }
            }
        }
        HLC+=8;
        LLC+=8;
        //cout << endl;
    }
}

void NumberTheGrid(){
    int n=1;
    int PCV=0;//Present Cell value
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            NumTravelGrid[i*8+j]=(PCV+n);
            if ((i==1)||(i==3)||(i==5)||(i==7)){
                NumGridCell[i][7-j]=(PCV+n);
            }
            else{
            NumGridCell[i][j]=(PCV+n); 
            }
            PCV=NumTravelGrid[i*8+j];
            
            if (CellTravelColor[i*8+j]!=0){
                n=CellTravelColor[i*8+j];
            }
        }
    }
   
}
void DetectColoredCells(){
    int r=0;
    int g=0;
    int b=0;
    int q=0;
    for (int p=0;p<8;p++){
        for (int u=0;u<8;u++){
            if ((p==1)||(p==3)||(p==5)||(p==7)){
                q=7-u;
            }
            else{
                q=u;
            }
            if (CellColor[p][q]!=0){
                if (CellColor[p][q]==2){
                    Red[r]=p;
                    Red[r+1]=q;
                    r+=2;   
                }
                else if(CellColor[p][q]==3){
                    Green[g]=p;
                    Green[g+1]=q;
                    g+=2;
                }
                else{
                    Blue[b]=p;
                    Blue[b+1]=q;
                    b+=2;
                }
            }        
        }
    }
}

void Gridupdate_2(){
    int ccheck=0;
    int numcolcells=0;
    for (int i=0;i<9;i++){
        for (int j=0;j<8;j++){
            if ((ccheck!=0)||(numcolcells==18)){
                ccheck=0;
                color[i*8+j]=0;
                //MoveOneNode();
                delay(500);
            }
            else{
                //detectcolour();
                delay(1600);
                color[i*8+j]=ccolor[i*8+j];
                if (ccolor[i*8+j]!=0){
                    //color[1*8+j+1]=0;
                    ccheck=1;
                    numcolcells+=1;
                }
                delay(500);
                //MoveOneNode();
                //Serial.println(time);
            }
        }
        if ((i/2)==1){
            delay(2500);
            // TurnLeft();
            // MoveOneNode();
            // TurnLeft();   
        }
        else{
            delay(2500);
            // TurnRight();
            // MoveOneNode();
            // TurnRight();
        }   
    }
}
void Gridupdate_3(){
    //Serial.println("done");
    // TurnRight();
    // MoveOneNode();
    // TurnLeft();
    delay(2500);
    int ccheck=0;
    int numcolcells=0;
    for (int i=0;i<4;i++){
        for (int j=0;j<8;j++){
            
            if ((ccheck!=0)||(numcolcells)==9){
                //Serial.println(ccolor_3[i*8+j]);
                ccheck=0;
                color_3[i*8+j]=0;
                delay(500);

                // MoveOneNode();

            }
            else{
                //detectcolour();
                delay(1600);
                color_3[i*8+j]=ccolor_3[i*8+j];
                //Serial.println(ccolor_3[i*8+j]);
                // MoveOneNode();
                delay(500);
                if (ccolor_3[i*8+j]!=0){
                    ccheck=1;
                    if ((i==0)||(i==2)){
                        delay(3200);
                        // TurnLeft();
                        // detectcolour();
                        array_3[numcolcells]=array_3dummy[numcolcells];
                        // TurnRight();

                    }
                    else{
                        // TurnRight();
                        // detectcolour();
                        delay(3600);
                        array_3[numcolcells]=array_3dummy[numcolcells];
                        // TurnRight();
                    }
                    numcolcells+=1;
                    
                    }

                
                
            }


        }
        if ((i/2)==1){
           // delay(3000);
            // TurnLeft();
            // MoveOneNode();
            //MoveOneNode();
            // TurnLeft();   
        }
        else{
            //delay(3000);
            // TurnRight();
            // MoveOneNode();
            //MoveOneNode();
            // TurnRight();
        }   

    }
}

void Cellcolorarray_3(){
    int numcol=0;
    for (int i=0;i<4;i++){
        for (int j=0; j<8; j++){
            if((i==0)||(i==2)){
                //Serial.print(i);
                if (color_3[i*8+j]==0){
                    CellColor[i*2][j]=0;
                    CellColor[i*2+1][j]=0;
                    // CellTravelColor[i*2*8+j]=0;
                    // CellTravelColor[i*2*8+7-j]=0;
                }
                else{
                    //Serial.println("Yes");
                    if (array_3[numcol]==1){
                        CellColor[i*2][j]=color_3[i*8+j];
                        CellColor[i*2+1][j]=0;
                        // CellTravelColor[i*2*8+j]=color_3[i*8+j];
                        // CellTravelColor[i*2*8+7-j]=0;
                       
                        //Serial.println(numcol);
                    }
                    else{
                        CellColor[i*2][j]=0;
                        CellColor[i*2+1][j]=color_3[i*8+j];
                        // CellTravelColor[i*2*8+j]=0;
                        // CellTravelColor[i*2*8+7-j]=color_3[i*8+j];

                    }
                     numcol+=1;
                    
                }
            }
            else{
                if (color_3[i*8+j]==0){
                    CellColor[i*2][7-j]=0;
                    CellColor[i*2+1][7-j]=0;
                    // CellTravelColor[i*2*8+7-j]=0;
                    // CellTravelColor[i*2*8+j]=0;
                }
                else{
                    //Serial.println("Yes");
                    if (array_3[numcol]==1){
                        CellColor[i*2][7-j]=color_3[i*8+j];
                        CellColor[i*2+1][7-j]=0;
                        // CellTravelColor[i*2*8+7-j]=color_3[i*8+j];
                        // CellTravelColor[i*2*8+j]=0;
                        
                        //Serial.println(numcol);
                    }
                    else{
                        CellColor[i*2][7-j]=0;
                        CellColor[i*2+1][7-j]=color_3[i*8+j];
                        // CellTravelColor[i*2*8+7-j]=0;
                        // CellTravelColor[i*2*8+j]=color_3[i*8+j];

                    }
                    numcol+=1;
                }

            }

        }
    }
}

void CellTRavel_update(){
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if ((i==0)||(i==2)||(i==4)||(i==6)){
                CellTravelColor[i*8+j]=CellColor[i][j];
            }
            else{
                CellTravelColor[i*8+j]=CellColor[i][7-j];
            }
        }
    }
}
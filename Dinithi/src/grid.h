
#include<ColorIdentification.h>
#include<Drive.h>
#include<globalspace.h>

int color[72];
int CellColor[8][8];
int ccolor[72]={0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,3,0,0,4,0,3,0,2,0,0,4,0,0,0,0,0,0,0,4,0,2,0,2,0,0,2,0,4,0,2,0,0,2,0,0,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,3,0,0,0,0};
int CellTravelColor[64];
int NumTravelGrid[64];
int NumGridCell[8][8];


void GridColorUpdate(){
    for (int i=0;i<9;i++){
        for (int j=0;j<8;j++){
            color[i*8+j]=Detectcolor();
        if ((i/2)==1){
            TurnLeft();
            MoveOneNode();
            TurnLeft();   
        }
        else{
            TurnRight();
            MoveOneNode();
            TurnRight();
        }
        }
    }
}

void CellColorArray(){
    GridColorUpdate();
    int HLC=15;
    int LLC=0;
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
        cout << endl;
    }
}

void NumberTheGrid(){
    int n=1;
    int PCV=0;
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
    for (int p=0;p<8;p++){
        for (int q=0;q<8;q++){
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
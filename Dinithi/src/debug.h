#include <iostream>
using namespace std;
#include<grid.h>


void CellColorArray(int color[],int CellColor[8][8],int CellTravelColor[64]){
    //GridColorUpdate(ccolor);
    int HLC=15;
    int LLC=0;
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (color[LLC+j]==color[HLC-j]){
                CellTravelColor[i*8+j]=color[LLC+j];
                if ((i==1)||(i==3)||(i==5)||(i==7)){
                    CellColor[i][7-j]=color[LLC+j];
                   //cout << i << " ";
                }
                else{
                    //cout << i << "  ";
                    CellColor[i][j]=color[LLC+j];
                }
            }
            else if(color[LLC+j]!=color[HLC-j]){
                CellTravelColor[i*8+j]=0;
                if ((i==1)||(i==3)||(i==5)||(i==7)){
                    CellColor[i][7-j]=0;
                    //cout << i << " ";
                }
                else{
                    //cout << i << " ";
                    CellColor[i][j]=0;
                }
            }
        }
        HLC+=8;
        LLC+=8;
        cout << endl;
    }
}

int main(){
    int ccolor[72]={0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,3,0,0,4,0,3,0,2,0,0,4,0,0,0,0,0,0,0,4,0,2,0,2,0,0,2,0,4,0,2,0,0,2,0,0,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,3,0,0,0,0};
    int CellColor[8][8];
    int CellTravelColor[64];
    CellColorArray(ccolor,CellColor,CellTravelColor);
    for (int i = 0; i < 9; i++) 
{ 
  for (int j = 0; j < 8; j++) 
  { 
      cout << ccolor[i*8+j] << " "; 
  } 
     
  // Newline for new row 
  cout << endl; 
}

cout << endl; 
cout << endl; 
cout << endl; 

  for (int i = 0; i < 8; i++) 
{ 
  for (int j = 0; j < 8; j++) 
  { 
      cout << CellColor[i][j] << " "; 
  } 
     
  // Newline for new row 
  cout << endl; 
}
cout << endl; 
cout << endl; 
cout << endl;

for (int i = 0; i < 8; i++) 
{ 
  for (int j = 0; j < 8; j++) 
  { 
      cout << CellTravelColor[i*8+j] << " "; 
  } 
     
  // Newline for new row 
  cout << endl; 
}
}

void NumberTheGrid(int CellTravelColor[64],int NumTravelGrid[64],int NumGridCell[8][8]){
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

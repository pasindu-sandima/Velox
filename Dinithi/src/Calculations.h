
#include <Line following.h>
#include<Drive.h>
#include<globalspace.h>


void CalculateColOrder(){
    int Redval=0;
    int Greenval=0;
    int Blueval=0;
    Redval=(NumGridCell[Red[0]][Red[1]])+(NumGridCell[Red[2]][Red[3]]*NumGridCell[Red[2]][Red[3]])+(NumGridCell[Red[4]][Red[5]]*NumGridCell[Red[4]][Red[5]])*NumGridCell[Red[4]][Red[5]];
    Blueval=(NumGridCell[Blue[0]][Blue[1]])+(NumGridCell[Blue[2]][Blue[3]]*NumGridCell[Blue[2]][Blue[3]])+(NumGridCell[Blue[4]][Blue[5]]*NumGridCell[Blue[4]][Blue[5]]*NumGridCell[Blue[4]][Blue[5]]);
    Greenval=(NumGridCell[Green[0]][Green[1]])+(NumGridCell[Green[2]][Green[3]]*NumGridCell[Green[2]][Green[3]])+(NumGridCell[Green[4]][Green[5]]*NumGridCell[Green[4]][Green[5]]*NumGridCell[Green[4]][Green[5]]);
    
    if (Blueval>Redval){
        if (Red>Green){
            Order[0]=3;//G
            Order[1]=2;//r
            Order[2]=4;//b
        }
        else if (Greenval>Blueval)
        {
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
    int n=0;
    int num=0;
    int LRF=0;
    while(n<=4){
        lineFollow();//Assign speed
        if (isJunction==true){
            Brake();
            n+=1;
            num+=10;
            CheckForPillars(LRF);
            Pillval+=n*num;
        MoveForward();//move a small num of steps
        }
    }
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

#ifndef GLOBAL_SPACE_H
#define GLOBAL_SPACE_H


//motor_controlling
#define rm1 10
#define rm2 9
#define Rpwm 8
#define lm1 12
#define lm2 13
#define Lpwm 11
volatile int countleft=0,countright=0;
int phasecount=0;
int lspeed=400; int rspeed=384;
int rampspeed = 300;

//Buttons
#define button1 36
#define button2 38
#define button3 40

#define buzzer 48


//line following
#define SLF 18//single line sensors
#define SLB 19
#define SRF 20
#define SRB 21
#define S1 A8 //leftmost
#define S2 A9
#define S3 A10
#define S4 A11
#define S5 A12
#define S6 A13
#define S7 A14
#define S8 A15 //rightmost
bool anysensor=true;
bool allsensors = false;
bool coinarea = false;
bool nosensors=false;
#define SC0 41        //S0
#define SC1 39       //s1
#define SC2 45
#define SC3 47
int colval;
int red=0,green=0,blue=0;
int colour=1; 
#define sensorOut 43
#define blueled 30
#define redled 32
#define greenled 34



//Junction detecting
volatile bool leftjunction=false,rightjunction=false;
bool junctionflag =  false;

//line following parameters
int n=0; int sum=0;int lineout=0; float error=0; float last_error=0; float adj=0;
bool stop=false;
int Kd=120, Kp=30,w1=1, w2=3, w3=8, w4=20, W5=4,w5=4,w6=1; // w5 = error is devided by this and the substracted from rspeed
int white_range = 75,br=100;

//drive forward
int Rspeed; int Lspeed;

//right and left turns
int lcount=0;
int rcount=0;
bool condition = true;





//Grid
long Redval=0;
long Greenval=0;
long Blueval=0;

// 
int color[72];
int CellColor[8][8];
int ccolor[72]={0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,3,0,0,4,0,3,0,2,0,0,4,0,0,0,0,0,0,0,4,0,2,0,2,0,0,2,0,4,0,2,0,0,2,0,0,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,3,0,0,0,0};
int CellTravelColor[64];
int NumTravelGrid[64]; 
long NumGridCell[8][8];
int Red[6];int Blue[6]; int Green[6];
int Order[3];
int MovetoCells[3][2];
int ccolor_3[32]={0,3,0,0,0,0,3,0,2,0,0,4,0,0,0,0,0,2,0,4,0,2,0,0,0,0,4,0,3,0,0,0};
int color_3[32];
int array_3[9];
int array_3dummy[9]={0,0,0,1,0,1,1,1,0};



//calculations
int thirdFromEnd[300]={0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,3 ,6 ,9 ,5 ,5 ,1 ,7 ,9 ,7 ,6 ,3 ,0 ,3 ,4 ,8 ,2 ,0 ,2 ,3 ,5 ,8 ,4 ,3 ,8 ,1 ,9 ,1 ,1 ,2 ,4 ,7 ,1 ,9 ,0 ,9 ,0 ,0 ,0 ,0 ,1 ,2 ,4 ,7 ,1 ,8 ,0 ,9 ,9 ,8 ,8 ,7 ,5 ,2 ,8 ,1 ,9 ,1 ,1 ,2 ,3 ,6 ,0 ,7 ,7 ,4 ,2 ,6 ,9 ,5 ,4 ,0 ,5 ,6 ,2 ,9 ,1 ,1 ,3 ,4 ,7 ,1 ,9 ,0 ,9 ,0 ,0 ,0 ,1 ,1 ,2 ,4 ,7 ,1 ,9 ,0 ,0 ,1 ,1 ,2 ,3 ,5 ,8 ,4 ,3 ,7 ,0 ,8 ,9 ,7 ,6 ,4 ,1 ,5 ,6 ,2 ,9 ,2 ,1 ,3 ,5 ,9 ,4 ,4 ,9 ,3 ,2 ,6 ,8 ,4 ,3 ,8 ,1 ,9 ,0 ,0 ,1 ,2 ,3 ,5 ,8 ,4 ,3 ,7 ,1 ,9 ,0 ,9 ,0 ,0 ,1 ,1 ,2 ,4 ,7 ,2 ,9 ,1 ,1 ,3 ,4 ,8 ,3 ,1 ,4 ,6 ,1 ,7 ,8 ,6 ,5 ,1 ,6 ,8 ,5 ,3 ,9 ,2 ,2 ,5 ,7 ,2 ,9 ,1 ,0 ,2 ,3 ,5 ,8 ,3 ,1 ,5 ,7 ,2 ,9 ,1 ,1 ,2 ,3 ,6 ,0 ,7 ,7 ,5 ,2 ,8 ,1 ,9 ,0 ,9 ,9 ,8 ,8 ,7 ,5 ,3 ,9 ,2 ,1 ,4 ,6 ,1 ,7 ,8 ,6 ,5 ,1 ,6 ,8 ,5 ,3 ,8 ,2 ,1 ,3 ,5 ,8 ,3 ,2 ,6 ,8 ,4 ,3 ,8 ,2 ,1 ,3 ,4 ,7 ,2 ,0 ,2 ,2 ,5 ,7 ,2 ,0 ,3 ,4 ,7 ,2 ,0 ,2 ,2 ,4 ,6 ,1 ,8 ,9 ,8 ,7 ,6 ,4 ,0 ,4 ,4 ,8 ,3 ,2 ,5 ,8 ,3 ,2 ,5 ,8 ,3 ,2 ,6};
int thirdfromfront[300]={0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 ,3 ,7 ,0 ,7 ,9 ,8 ,8 ,6 ,9 ,7 ,6 ,3 ,0 ,1 ,6 ,7 ,4 ,2 ,4 ,7 ,2 ,0 ,2 ,9 ,1 ,0 ,2 ,2 ,5 ,7 ,3 ,1 ,3 ,3 ,7 ,0 ,7 ,5 ,3 ,9 ,3 ,2 ,9 ,5 ,5 ,1 ,6 ,4 ,0 ,5 ,5 ,6 ,1 ,7 ,9 ,7 ,7 ,0 ,8 ,8 ,6 ,0 ,1 ,1 ,2 ,4 ,4 ,4 ,8 ,3 ,1 ,0 ,9 ,0 ,9 ,0 ,7 ,8 ,6 ,4 ,2 ,7 ,9 ,6 ,6 ,5 ,8 ,4 ,3 ,7 ,0 ,2 ,2 ,5 ,2 ,6 ,9 ,5 ,4 ,4 ,4 ,8 ,3 ,1 ,6 ,4 ,1 ,5 ,7 ,0 ,6 ,7 ,4 ,1 ,5 ,1 ,7 ,9 ,6 ,2 ,9 ,1 ,0 ,8 ,1 ,9 ,0 ,0 ,1 ,2 ,3 ,5 ,8 ,5 ,5 ,0 ,6 ,6 ,1 ,0 ,2 ,3 ,0 ,8 ,9 ,8 ,7 ,2 ,8 ,1 ,9 ,0 ,5 ,0 ,6 ,6 ,2 ,0 ,4 ,4 ,8 ,3 ,7 ,0 ,7 ,8 ,4 ,5 ,0 ,5 ,5 ,7 ,5 ,2 ,8 ,1 ,0 ,8 ,9 ,7 ,6 ,6 ,2 ,9 ,2 ,7 ,3 ,0 ,3 ,4 ,8 ,2 ,1 ,3 ,4 ,1 ,3 ,5 ,8 ,3 ,6 ,6 ,2 ,9 ,0 ,2 ,2 ,4 ,6 ,1 ,9 ,0 ,0 ,1 ,3 ,9 ,2 ,2 ,4 ,6 ,1 ,7 ,8 ,6 ,1 ,5 ,6 ,2 ,3 ,8 ,1 ,0 ,2 ,5 ,6 ,1 ,8 ,9 ,7 ,6 ,4 ,1 ,5 ,1 ,9 ,0 ,0 ,1 ,7 ,4 ,1 ,5 ,7 ,4 ,1 ,6 ,8 ,9 ,3 ,2 ,5 ,8 ,2 ,4 ,6 ,1 ,7 ,6 ,7 ,4 ,2 ,0 ,2 ,3 ,6 ,0 ,1 ,0 ,2 ,3 ,5 ,3 ,0 ,4 ,4 ,8 ,7 ,2};
int Pillval=0;
int LRB=0; int pillpos=0; int pillposval=0;

//Drive
bool isJunction=false;
int CNr; int CNc; int DNr; int DNc;
int Face=0;

//tofSetup
int distanceL; int distanceR; int distanceFR; int distanceFL;

//OLED function
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)


#endif
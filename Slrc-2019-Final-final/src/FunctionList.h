//calculations
void CalculateColOrder();
void GenPillVal();
void CalculateRBGSquares();
void Pillars();
void CheckForPillars();

//debug
void Buzz(uint16_t time);
void GridSolve();
void Task();
void uptoPillars();
void Pillars();
void ToArea1();
void EnteringArea1();
void LeavingArea1();
void EnterArea2();
void FinishTask();

//Drive
void MoveOneNode();
void GoToNode();
void TurnLeft();
void TurnRight();
void Turn180();
void countForward(int count);
void MoveForward(int rspeed,int lspeed);
void drive(int rspeed,int lspeed);
void Brake();
void Turn(int dir);
void Decelarate();
void TurnRight45();
void TurnLeft45();
void Reverse();
void CorrectPosition();
void TurnRightSlow();
void encoderback();
void TurnLeftSlow();


//grid
//void GridColorUpdate();
//void CellColorArray();
void NumberTheGrid();
void DetectColoredCells();
void Gridupdate_3();
void Cellcolorarray_3();
void CellTRavel_update();
void DetachCoins();
void Gridupdate_4();

//interrupts
void rjunction();
void ljunction();
void rightcount();
void leftcount();

//Line following&color
void lineFollow();
void detectcolour();

//MeasureDistance
void tofSetup();
void getTOFReading();
void measure();
void measuresingle();
void startTOF();
void stopTOF();

//NRF
void initNRF();
void check_completion();
void indicategreen1();
void indicateblue1();
void indicatered1();
void indicategreen2();
void indicateblue2();
void indicatered2();
void indicategreen3();
void indicateblue3();
void indicatered3();

//pin_Modes
void pinModes();

//OLED
void initialize_OLED();
void OLEDprint(char word);
void OLED_print(int value);
void Print_Green();
void Print_Red();
void Print_Blue();
void OLED_Display(String text);
void Print_Velox();






//servo
void TurnCoinOne();
void TurnCoinTwo();
void TurnCoinThree();
void TurnDoorAttach();
void MagnetRelease();
void MagnetNormal();
void AssARMdown();
void AssARMup();


//NRF
void check_completion();
void indicategreen1();
void indicatered1();
void indicateblue1();
void initNRF();

//Servo
void servosetup();
void MagnetNormal();
void MagnetRelease();
void AssARMdown();
void AssARMup();
void TurnDoorAttach();
void TurnCoinOne();
void TurnCoinTwo();
void TurnCoinThree();


void uptoPillars();
void AccStraight();

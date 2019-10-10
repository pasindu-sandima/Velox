//calculations
void CalculateColOrder();
void GenPillVal();
void CalculateRBGSquares();

//Drive
void MoveOneNode();
void GoToNode();
void TurnLeft();
void TurnRight();
void Turn180();
void countForward(int count);
void CheckForPillars();
void MoveForward(int rspeed,int lspeed);
void Brake();
void Turn(int dir);

//grid
void GridColorUpdate();
void CellColorArray();
void NumberTheGrid();
void DetectColoredCells();

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

//pin_Modes
void pinModes();

//OLED
void OLEDprint(char word);
void Print_Green();
void Print_Red();
void Print_Blue();


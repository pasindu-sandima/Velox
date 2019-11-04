#define XSHUT_pin1 23           //Right Sensor
#define XSHUT_pin2 25           //Left Sensor
#define XSHUT_pin3 27           //Front Sensor  Right  
#define XSHUT_pin4 29           //Front Sensor Left

#define Sensor1_newAddress 42
#define Sensor2_newAddress 43
#define Sensor3_newAddress 44
#define Sensor4_newAddress 45

#define SignalRateLimit 0.8          //Higher the limit , higher the accuracy
#define MeasurementBudget 60000      //Higher the time , higher the accuracy
#define Timeout 200
#define ContInterval 40 //inter-measurement period in milliseconds determining how often the sensor takes a measurement.


VL53L0X Sensor1;      //Right Sensor
VL53L0X Sensor2;      //Left Sensor
VL53L0X Sensor3;      //Front Sensor
VL53L0X Sensor4;


void tofSetup(){ /*WARNING*/
  //Shutdown pins of VL53L0X ACTIVE-LOW-ONLY NO TOLERANT TO 5V will fry them
  pinMode(XSHUT_pin1, OUTPUT);
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(XSHUT_pin3, OUTPUT);
  pinMode(XSHUT_pin4, OUTPUT);
  digitalWrite(XSHUT_pin1,LOW);
  digitalWrite(XSHUT_pin2,LOW);
  digitalWrite(XSHUT_pin3,LOW);
  digitalWrite(XSHUT_pin4,LOW);
  delay(50);

  
  pinMode(XSHUT_pin4,INPUT);
  delay(10);
  Sensor4.setAddress(Sensor4_newAddress);

  pinMode(XSHUT_pin3,INPUT);
  delay(10);
  Sensor3.setAddress(Sensor3_newAddress);
  
  pinMode(XSHUT_pin2,INPUT);
  delay(10);
  Sensor2.setAddress(Sensor2_newAddress);
  
  pinMode(XSHUT_pin1, INPUT);
  delay(10);
  Sensor1.setAddress(Sensor1_newAddress);
  
 
  if(Sensor1.init()){
    Serial.println("Sensor 1 : Configured");
  }
  else
  {
    Serial.println("Sensor 1 : Configuration Failed");
  }
  if(Sensor2.init()){
    Serial.println("Sensor 2 : Configured");
  }
  else
  {
    Serial.println("Sensor 2 : Configuration Failed");
  }
    if(Sensor3.init()){
    Serial.println("Sensor 3 : Configured");
  }
  else
  {
    Serial.println("Sensor 3 : Configuration Failed");
  }
  if(Sensor4.init()){
    Serial.println("Sensor 4 : Configured");
  }
  else
  {
    Serial.println("Sensor 4 : Configuration Failed");
  }
  // Sensor1.setSignalRateLimit(0.8);
  // Sensor2.setSignalRateLimit(0.9);
  Sensor3.setSignalRateLimit(0.9);
  Sensor4.setSignalRateLimit(0.9);

  // Sensor1.setMeasurementTimingBudget(MeasurementBudget);
  // Sensor2.setMeasurementTimingBudget(MeasurementBudget);
  // Sensor3.setMeasurementTimingBudget(MeasurementBudget);
  // Sensor4.setMeasurementTimingBudget(MeasurementBudget);


  // Sensor1.setTimeout(Timeout);
  // Sensor2.setTimeout(Timeout);
  // Sensor3.setTimeout(Timeout);
  // Sensor4.setTimeout(Timeout);
  Sensor1.startContinuous();
  Sensor2.startContinuous();
  Sensor3.startContinuous();
  Sensor4.startContinuous();

 
}

void getTOFReading(){
  measure();
  Serial.print(distanceR);
  Serial.print(",  ");
  Serial.print(distanceL);
  Serial.print(",  ");
  Serial.print(distanceFR);
  Serial.print(",  ");
  Serial.println(distanceFL);
  // Serial.print(Sensor1.readRangeContinuousMillimeters());
  // Serial.print(",  ");
  // Serial.print(Sensor2.readRangeContinuousMillimeters());
  // Serial.print(",  ");
  // Serial.print(Sensor3.readRangeContinuousMillimeters());
  // Serial.print(",  ");
  // Serial.println(Sensor4.readRangeContinuousMillimeters());
  // Serial.println(",  ");

  delay(50);
}

void measure(){
  distanceR = Sensor3.readRangeContinuousMillimeters()+6;
  distanceL = Sensor4.readRangeContinuousMillimeters()+16;
  // distanceFR= Sensor1.readRangeContinuousMillimeters();
  // distanceFL= Sensor2.readRangeContinuousMillimeters()+10;

}

void measuresingle(){
  distanceR = Sensor1.readRangeSingleMillimeters();
  distanceL = Sensor2.readRangeSingleMillimeters();
  distanceFR= Sensor3.readRangeSingleMillimeters();
  distanceFL=Sensor4.readRangeSingleMillimeters();
}

void startTOF(){
  Sensor1.startContinuous();
  Sensor2.startContinuous();
  Sensor3.startContinuous();
  Sensor4.startContinuous();
}


void stopTOF(){
  Sensor1.stopContinuous();
  Sensor2.stopContinuous();
  Sensor3.stopContinuous();
  Sensor4.stopContinuous();
}

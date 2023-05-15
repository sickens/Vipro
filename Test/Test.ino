#include <AccelStepper.h>

const int LstepPin = 3;
const int LdirPin = 4;
const int RstepPin = 5;
const int RdirPin = 6;
const int stepsPerRevolution = 12500;

AccelStepper Lstepper(AccelStepper::DRIVER, LstepPin, LdirPin);
AccelStepper Rstepper(AccelStepper::DRIVER, RstepPin, RdirPin);

//CHANGE THIS VALUE(mL/sec) AND MAKE SURE TO UPLOAD CODE BEFORE RUNNING
const float LmLPerSecond = 0.04;
const float RmLPerSecond = 0.04;

float Lspeed = LmLPerSecond*20;
float Rspeed = LmLPerSecond*20;

void setup()
{
  
  Lstepper.setMaxSpeed(10);
  Lstepper.setSpeed(Lspeed);

  Rstepper.setMaxSpeed(10);
  Rstepper.setSpeed(Rspeed);

  //del = (1/( mLPerSecond / .05 * stepsPerRevolution )) * 1000000/2;
}


void loop()
{
  Lstepper.runSpeed();
  Rstepper.runSpeed();
}

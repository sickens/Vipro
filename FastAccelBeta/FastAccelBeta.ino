#include "FastAccelStepper.h"

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *Lstepper = NULL;
FastAccelStepper *Rstepper = NULL;

#define LstepPin  9
#define LdirPin   8

#define RstepPin  10
#define RdirPin   11

//CHANGE THIS VALUE(mL/sec) AND MAKE SURE TO UPLOAD CODE BEFORE RUNNING
//the upper limit is 0.148 mL/sec because of limitations of the FastAccelStepper library
const float LmLPerSecond = 0.05;
const float RmLPerSecond = 0.05;

float Lspeed = 250000 * LmLPerSecond;
float Rspeed = 250000 * RmLPerSecond;

void setup() {
   engine.init();
   //Left Stepper
   Lstepper = engine.stepperConnectToPin(LstepPin);
   if (Lstepper) {
      Lstepper->setDirectionPin(LdirPin);
      //stepper->setEnablePin(enablePinStepper);
      //stepper->setAutoEnable(true);

      Lstepper->setSpeedInHz(Lspeed);
      Lstepper->setAcceleration(INT32_MAX);
      Lstepper->runForward();   
   }

   //Right Stepper
   Rstepper = engine.stepperConnectToPin(RstepPin);
   if (Rstepper) {
      Lstepper->setDirectionPin(RdirPin);
      //stepper->setEnablePin(enablePinStepper);
      //stepper->setAutoEnable(true);

      Rstepper->setSpeedInHz(Rspeed);
      Rstepper->setAcceleration(INT32_MAX);
      Rstepper->runForward();
   }
}

void loop() {}
const int stepPin = 3;
const int dirPin = 4;
const int stepPin2 = 5;
const int dirPin2 = 6;
const int stepsPerRevolution = 12500;
int del;

//CHANGE THIS VALUE(mL/sec) AND MAKE SURE TO UPLOAD CODE BEFORE RUNNING
const float mLPerSecond = 0.04;

void setup()
{
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  del = (1/( mLPerSecond / .05 * stepsPerRevolution )) * 1000000/2;
}


void loop()
{
  digitalWrite(dirPin, HIGH);
  digitalWrite(dirPin2, HIGH);

  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(del);
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(del);
  }
}

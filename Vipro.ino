const int stepPin = 3;
const int dirPin = 4;
const int stepPin2 = 5;
const int dirPin2 = 6;

const int stepsPerRevolution = 12500;
const int del = 50;


void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}


void loop()
{
  // Set motor direction clockwise
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

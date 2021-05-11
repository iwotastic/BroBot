#include "./State.h"

// This is empty because Halted just waits to start inside of `getNextState`.
void Halted::process() {}

State* Halted::getNextState() {
  Robot::current()->motors.setSpeeds(0, 0);
  Robot::current()->zumoButton.waitForButton();
  delay(5000);
  return new Scanning();
}

void Scanning::process() {
  
}

State* Scanning::getNextState() {
  return nullptr;
}

// This is also empty because retreat backs up in a "dead reckoning" style where it only goes for a little bit.
void Retreat::process() {}

State* Retreat::getNextState() {
  Robot::current()->motors.setSpeeds(-300, -300);
  delay(1000); // Adjust delay as needed
  Robot::current()->motors.setSpeeds(0, 0);
  return nullptr;
}

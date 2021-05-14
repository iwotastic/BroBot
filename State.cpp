#include "./State.h"

// This is empty because Halted just waits to start inside of `getNextState`.
void Halted::process() {}

State* Halted::getNextState() {
  Robot::current()->motors.setSpeeds(0, 0);
  Robot::current()->zumoButton.waitForButton();
  Robot::current()->recalibrate();
  delay(5000);
  return new Scanning();
}

void Scanning::process() {
  // Turn *ever* so slowly...
  Robot::current()->motors.setSpeeds(200, -200);
}

State* Scanning::getNextState() {
  if (Robot::current()->safeRightDist * 0.5 > Robot::current()->getRightDist()) {
    digitalWrite(13, HIGH);
    return new Attack();
  }
  return nullptr;
}

void Attack::process() {
  // To quote Jeremy Clarkson, "POWAAAAaaah!!!"
  Robot::current()->motors.setSpeeds(400, 400);
}

State* Attack::getNextState() {
  // To decide when to attack, we use the built-in line detecting sensor array. It measures light based on pulse time: the lesser the pulse, the brighter the surface.
  unsigned int* lineValues = Robot::current()->getLineValues();
  if (lineValues[0] < LS_THRESHOLD || lineValues[LS_NUM_SENSORS - 1] < LS_THRESHOLD) {
    digitalWrite(13, LOW);
    return new Retreat();
  }
  return nullptr;
}

// This is also empty because retreat backs up in a "dead reckoning" style where it only goes for a little bit.
void Retreat::process() {}

State* Retreat::getNextState() {
  Robot::current()->motors.setSpeeds(-400, -400);
  delay(400); // Adjust delay as needed
  Robot::current()->motors.setSpeeds(-300, 300);
  delay(250); // Adjust delay as needed
  Robot::current()->motors.setSpeeds(0, 0);
  return new Scanning();
}

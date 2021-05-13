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
  // Turn *ever* so slowly...
  Robot::current()->motors.setSpeeds(200, -200);
}

State* Scanning::getNextState() {
  if (Robot::current()->safeLeftDist * 0.8 > Robot::current()->getLeftDist() && Robot::current()->safeRightDist * 0.8 > Robot::current()->getRightDist()) {
    Serial.println("Attack");
  }
  return nullptr;
}

void Attack::process() {
  // To quote Jeremy Clarkson, "POWAAAAaaah!!!"
  Robot::current()->motors.setSpeeds(400, 400);
}

State* Attack::getNextState() {
  // To decide when to attack, we use the built-in line detecting sensor array. It measures light based on pulse time: the lesser the pulse, the brighter the surface.
  
  if (true) {
    Serial.println("Attack");
  }
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

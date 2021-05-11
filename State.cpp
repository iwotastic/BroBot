#include "./State.h"

// This is empty because Halted just waits to start inside of `getNextState`.
void Halted::process() {}

State* Halted::getNextState() {
  Robot::current()->zumoButton.waitForButton();
  return new Scan();
}

void Scan::process() {
  
}

State* Scan::getNextState() {
  return nullptr;
}

#pragma once

#include <Arduino.h>
#include <ZumoShield.h>

class Robot {
  public:
  static Robot* current();

  Pushbutton zumoButton {ZUMO_BUTTON};
  ZumoMotors motors;

  private:
  static Robot* singleton;
  
  Robot() {};
};

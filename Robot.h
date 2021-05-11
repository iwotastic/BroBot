#pragma once

#include <Arduino.h>
#include <ZumoShield.h>

class Robot {
  public:
  static Robot* current();

  Pushbutton zumoButton {ZUMO_BUTTON};

  private:
  static Robot* singleton;
  
  Robot() {};
};

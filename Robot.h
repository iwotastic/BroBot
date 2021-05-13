#pragma once

#include "./Constants.h"
#include <Arduino.h>
#include <ZumoShield.h>

// This is the container class for all 
class Robot {
  public:
  static Robot* current();

  Pushbutton zumoButton {ZUMO_BUTTON};
  ZumoMotors motors;
  ZumoReflectanceSensorArray lineSensors {ZUMO_SENSOR_ARRAY_DEFAULT_EMITTER_PIN, LS_NUM_SENSORS};

  float getLeftDist();
  float getRightDist();

  void recalibrate();

  float safeLeftDist;
  float safeRightDist;

  unsigned int lineValues[LS_NUM_SENSORS];
  unsigned int* getLineArray();

  private:
  static Robot* singleton;
  
  Robot();
};

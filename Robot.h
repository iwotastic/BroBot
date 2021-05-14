#pragma once

#include "./Constants.h"
#include <Arduino.h>
#include <ZumoShield.h>

// This is the container class for all 
class Robot {
  public:
  static Robot* current();

  unsigned char lsPinsUsed[2] = {4, 5};

  Pushbutton zumoButton {ZUMO_BUTTON};
  ZumoMotors motors;
  ZumoReflectanceSensorArray lineSensors = ZumoReflectanceSensorArray(lsPinsUsed, LS_NUM_SENSORS, 2000, ZUMO_SENSOR_ARRAY_DEFAULT_EMITTER_PIN);

  float getRightDist();

  void recalibrate();

  float safeRightDist;

  unsigned int lineValues[LS_NUM_SENSORS];
  unsigned int* getLineValues();

  private:
  static Robot* singleton;
  
  Robot();
};

#include "./Robot.h"

Robot* Robot::singleton = nullptr;

Robot* Robot::current() {
  if (singleton == nullptr) singleton = new Robot();
  
  return singleton;
}

Robot::Robot() {
  // Set up ultrasonic pins on singleton init.
  pinMode(LEFT_ECHO, INPUT);
  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(RIGHT_TRIG, OUTPUT);

  recalibrate();
}

void Robot::recalibrate() {
  // Take an average safe distance value
  safeLeftDist = 0;
  safeRightDist = 0;
  for (int i = 0; i < 5; i++) {
    safeLeftDist += getLeftDist();
    safeRightDist += getRightDist();
  }
  safeLeftDist /= 5.0;
  safeRightDist /= 5.0;
}

// Gets the left ultrasonic distance
float Robot::getLeftDist() {
  digitalWrite(LEFT_TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(LEFT_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_TRIG, LOW);
  
  return pulseIn(LEFT_ECHO, HIGH) * 0.034 / 2;
}

// Gets the right ultrasonic distance
float Robot::getRightDist() {
  digitalWrite(RIGHT_TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(RIGHT_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(RIGHT_TRIG, LOW);
  
  return pulseIn(RIGHT_ECHO, HIGH) * 0.034 / 2;
}

// Get the raw line sensor data
unsigned int* Robot::getLineArray() {
  lineSensors.read(lineValues);
  return lineValues;
}

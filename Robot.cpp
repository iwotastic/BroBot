#include "./Robot.h"

Robot* Robot::singleton = nullptr;

Robot* Robot::current() {
  if (singleton == nullptr) singleton = new Robot();
  
  return singleton;
}

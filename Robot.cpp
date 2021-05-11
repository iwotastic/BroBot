#include "./Robot.h"

Robot* Robot::current() {
  if (singleton == nullptr) singleton = new Robot();
  
  return singleton;
}

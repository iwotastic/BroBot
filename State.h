#pragma once

#include <Arduino.h>
#include <ZumoShield.h>

class State {
  public:
  State() = default;
  virtual void process();
};

class Halted: public State {
  public:
  void process();
};
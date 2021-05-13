#pragma once

#include "./Robot.h"

// Base state class, used in other states. States represent self-contained actions the robot can take. Ironically, they should be
// as state-less as possible.
class State {
  public:
  State() = default;

  // `process` handles one tick of of Arduino.h's `loop`.
  virtual void process();

  // `getNextState` should return nullptr if we aren't supposed to continue, and a `State*` if we are.
  virtual State* getNextState();
};

class Halted: public State {
  public:
  void process();
  State* getNextState();
};

class Scanning: public State {
  public:
  void process();
  State* getNextState();
};

class Attack: public State {
  public:
  void process();
  State* getNextState();
};

class Retreat: public State {
  public:
  void process();
  State* getNextState();
};

#include "./Constants.h"
#include "./State.h"

// Set up a state pointer to hold current state. I use the word state, but these are more like FRC-style
// `Command`s merged with state because I can't be bother to state machine correctly.
State* state = nullptr;
State* nextState = nullptr;

long duration = 0;

void setup() {
  // Set up initial state.
  Serial.begin(9600);
  state = new Halted();
}

void loop() {
  // Process one tick of current state...
  state->process();

  // Get the next state...
  nextState = state->getNextState();
  if (nextState != nullptr) {
    // If it isn't a null pointer, drop current state and move next state...
    free(state);
    state = nextState;
  }
}

#include <Wire.h>
#include <ZumoShield.h>
#include "./Constants.h"
#include "./State.h"

// Set up a state pointer to hold current state. I use the word state, but these are more like FRC-style
// `Command`s merged with state because I can't be bother to state machine correctly.
State* state = nullptr;
State* nextState = nullptr;

long duration = 0;

void setup() {
  // Set up initial state.
  state = new Halted();
  
  Wire.begin();
  
  pinMode(LEFT_ECHO, INPUT);
  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  Serial.begin(9600);
}

/*
  digitalWrite(LEFT_TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(LEFT_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_TRIG, LOW);
  
  duration = pulseIn(LEFT_ECHO, HIGH);
  Serial.print("L Distance (cm): ");
  Serial.println(duration * 0.034 / 2);
*/

void loop() {
  // Process one tick of current state...
  state->process();

  // Get the next state...
  nextState = state->getNextState();
  if (nextState != nullptr) {
    // If it isn't a null pointer, drop current state and move next state...
    delete(state);
    state = nextState;
    delete(nextState);
  }
}

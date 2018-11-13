#ifndef _STARTLE_H_
#define _STARTLE_H_

#include "Creature.h"
#include "State.h"

#define STARLE_FACTOR 30 // TODO: may change
// #define STARTLE_THRESHOLD_DECAY GLOBALS.STARTLE_THRESHOLD_DECAY // This is a float

class Startle : public State {
 public:
  Startle(Creature& creature) : State(creature, "Startle", 0) {}
  uint8_t getNumRepeats();
  State* transition() override;
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _Startle_H_

#ifndef _ACTIVE_1_H_
#define _ACTIVE_1_H_

#include "Creature.h"
#include "State.h"

#define STARLE_FACTOR 30 // TODO: may change
// #define STARTLE_THRESHOLD_DECAY GLOBALS.STARTLE_THRESHOLD_DECAY // This is a float

class Active_1 : public State {
 public:
  Active_1(Creature& creature) : State(creature, "Active_1", 0) {}
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

#endif  // _Active_1_H_

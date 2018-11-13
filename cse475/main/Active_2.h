#ifndef _ACTIVE_2_H_
#define _ACTIVE_2_H_

#include "Creature.h"
#include "State.h"

class Active_2 : public State {
  Active_2(Creature &creature) : State(creature, "Active_2", 2) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif

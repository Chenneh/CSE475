#include "Creature.h"
#include "State.h"

State::State(Creature& creature, char* const name, const uint8_t id) : _creature(creature), _id(id) {
  strncpy(_name, name, MAX_NAME_LEN);
  _name[MAX_NAME_LEN] = 0;
};

uint8_t State::getId() {
  return _id;
}

char* State::getName() {
  return _name;
}

void State::playSound(uint8_t sound_idx) {
  // TODO: implement
}

void State::playEffect(uint8_t effect_idx) {
  // TODO: implement
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  int8_t param =  (STARTLE_DECAY - rssi) / STARTLE_DECAY;
  int8_t func = 1 / (1 + exp((-1) * param));
  int8_t decay = func * this->getStartleFactor;
  this->startled(decay * payload[0], playload[1]);
  return true;
}

void State::txStartle(uint8_t strength, uint8_t id) {
  uint8_t payload[] = {strength, id};
  _creature.tx(PID_STARTLE, BROADCAST_ADDR, sizeof(payload), payload);
}

State* State::transition() {
  const uint8_t *localWeights = this->getLocalWeights();
  double norm_localWeights[7];
  int sum = 0;
  for (int i = 0; i < 7; i++) {
    norm_localWeights[i] = sum + localWeights[i];
    sum += localWeights[i];
  }
  for (int i = 0; i < 7; i++) {
    norm_localWeights[i] = norm_localWeights[i] / sum;
  }

  int r = rand() / (RAND_MAX + 1.);
  int next_state_id = 0;
  for (int i = 0; i < 7; i++) {
    if (norm_localWeights[i] < r) {
      next_state_id++;
    }
  }
  switch(next_state_id) {
    case 1: return new Ambient_1(_creature); break;
    case 2: return new Active_1(_creature); break;
    case 3: return new Ambient_2(_creature); break;
    case 4: return new Active_2(_creature); break;
    case 5: return new Ambient_3(_creature); break;
    case 6: return new Active_3(_creature); break;
  }
}

void State::PIR() {
  // TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  if (id != _creature.getLastStartleId()) {
    uint32_t time = millis();
    uint32_t lastTime = _creature.getLastStartle();
    uint8_t oldTh = _creature._startleThreshold;
    _creature._startleThreshold = oldTh - oldTh * (time - lastTime) * STARTLE_THRESHOLD_DECAY * this->getStartleFactor();
    if (strength >= ) { // what is state.threshold();??????
      _creature->_transition(new Startle(_creature));
      this->txStartle(strength, id);
      _creature._lastStartleId = id;
    }
    _creature._lastStartle = time;
  }
}

int8_t* State::getGlobalWeights() {
  return _globalWeights;
}

#include "Startle.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 return rand() % 5 + 1; // 1 - 5 repeats
}

void Startle::loop(uint32_t dt) {
  Midi::setSound(25);
  Neopixel::setLight(12);
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}

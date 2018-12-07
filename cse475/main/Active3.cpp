#include "Active3.h"
#include "Debug.h"
#include "Midi.h"

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
 return rand() % 5 + 1; // 1 - 5 repeats
}

void Active3::loop(uint32_t dt) {
  Midi::setSound(0x1F);
  Neopixel::setLight(5);
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.001f;
}

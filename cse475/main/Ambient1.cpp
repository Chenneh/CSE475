#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 return rand() % 5 + 1; // 1 - 5 repeats
}

void Ambient1::loop(uint32_t dt) {
  Midi::setSound(13);
  Neopixel::setLight(9);
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}

#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 //return rand() % 5 + 4; // 4 - 8 repeats
 return 2;
}

void Ambient1::loop(uint32_t dt) {
  Midi::setSound(18);
  //Sound * amSound1 = Midi::SOUNDS[26];
  //int nodeNum = sizeof(amSound1->duration);
  //Neopixel::yellow(1, nodeNum);
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}

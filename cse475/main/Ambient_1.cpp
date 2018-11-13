#include "Ambient_1.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Ambient_1::_localWeights[];

uint8_t Ambient_1::getNumRepeats() {
 return 32;
}

State* Ambient_1::transition() {
  Midi::setSound(Midi::getSound() ? 0 : 1);
  Neopixel::setLight(Neopixel::getLight() ? 0 : 1);
  return this;
}

void Ambient_1::loop(uint32_t dt) {
//  dprintln(F("Ambient_1ing..."));
}

const uint8_t* Ambient_1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient_1::getStartleFactor() {
  return STARLE_FACTOR;
}

void Ambient_1::PIR() {
  dprintln("PIR triggered!");
}

void Ambient_1::startled(uint8_t strength, uint8_t id) {}

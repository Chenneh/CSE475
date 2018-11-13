#include "Active_1.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Active_1::_localWeights[];

uint8_t Active_1::getNumRepeats() {
 return 32;
}

State* Active_1::transition() {
  Midi::setSound(Midi::getSound() ? 0 : 1);
  Neopixel::setLight(Neopixel::getLight() ? 0 : 1);
  return this;
}

void Active_1::loop(uint32_t dt) {
//  dprintln(F("Active_1ing..."));
}

const uint8_t* Active_1::getLocalWeights() {
  return this->_localWeights;
}

float Active_1::getStartleFactor() {
  return STARLE_FACTOR;
}

void Active_1::PIR() {
  dprintln("PIR triggered!");
}

void Active_1::startled(uint8_t strength, uint8_t id) {}

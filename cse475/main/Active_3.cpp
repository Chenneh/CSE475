#include "Active_3.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Active_3::_localWeights[];

uint8_t Active_3::getNumRepeats() {
 return 32;
}

State* Active_3::transition() {
  Midi::setSound(Midi::getSound() ? 0 : 1);
  Neopixel::setLight(Neopixel::getLight() ? 0 : 1);
  return this;
}

void Active_3::loop(uint32_t dt) {
//  dprintln(F("Active_3ing..."));
}

const uint8_t* Active_3::getLocalWeights() {
  return this->_localWeights;
}

float Active_3::getStartleFactor() {
  return STARLE_FACTOR;
}

void Active_3::PIR() {
  dprintln("PIR triggered!");
}

void Active_3::startled(uint8_t strength, uint8_t id) {}

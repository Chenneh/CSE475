#include "Ambient_3.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Ambient_3::_localWeights[];

uint8_t Ambient_3::getNumRepeats() {
 return 32;
}

State* Ambient_3::transition() {
  Midi::setSound(Midi::getSound() ? 0 : 1);
  Neopixel::setLight(Neopixel::getLight() ? 0 : 1);
  return this;
}

void Ambient_3::loop(uint32_t dt) {
//  dprintln(F("Ambient_3ing..."));
}

const uint8_t* Ambient_3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient_3::getStartleFactor() {
  return STARLE_FACTOR;
}

void Ambient_3::PIR() {
  dprintln("PIR triggered!");
}

void Ambient_3::startled(uint8_t strength, uint8_t id) {}

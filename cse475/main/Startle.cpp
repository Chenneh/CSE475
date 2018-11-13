#include "Startle.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 return 32;
}

State* Startle::transition() {
  Midi::setSound(Midi::getSound() ? 0 : 1);
  Neopixel::setLight(Neopixel::getLight() ? 0 : 1);
  return this;
}

void Startle::loop(uint32_t dt) {
//  dprintln(F("Startleing..."));
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return STARLE_FACTOR;
}

void Startle::PIR() {
  dprintln("PIR triggered!");
}

void Startle::startled(uint8_t strength, uint8_t id) {}

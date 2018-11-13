#include "Ambient_2.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Ambient_2::_localWeights[];

uint8_t Ambient_2::getNumRepeats() {
 return 32;
}

void Ambient_2::loop(uint32_t dt) {
  dprintln(F("Ambient_2ing..."));
}

const uint8_t* Ambient_2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient_2::getStartleFactor() {
  return 10;
}

void Ambient_2::PIR() {
  dprintln("PIR triggered!");
}

void Ambient_2::startled(uint8_t strength, uint8_t id) {
  dprintln("From Ambient_2 startled!");
}

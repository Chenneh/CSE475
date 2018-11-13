#include "Active_2.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Active_2::_localWeights[];

uint8_t Active_2::getNumRepeats() {
 return 32;
}

void Active_2::loop(uint32_t dt) {
  dprintln(F("Active_2ing..."));
}

const uint8_t* Active_2::getLocalWeights() {
  return this->_localWeights;
}

float Active_2::getStartleFactor() {
  return 10;
}

void Active_2::PIR() {
  dprintln("PIR triggered!");
}

void Active_2::startled(uint8_t strength, uint8_t id) {
  dprintln("From Active_2 startled!");
}

#include "Neopixel.h"
#include "Debug.h"

// Initialize fixed list of light gestures.
//void (*Neopixel::LIGHTS[2])(uint32_t) = {nullptr, &rainbow};
constexpr void (*Neopixel::LIGHTS[])(uint32_t);
uint8_t Neopixel::_myDelay = 0;
uint8_t Neopixel::_currentIdx = 0;
uint32_t Neopixel::_lastLoop = 0;
Adafruit_NeoPixel_ZeroDMA Neopixel::_strip = Adafruit_NeoPixel_ZeroDMA(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRBW);

void Neopixel::setup() {
  _strip.begin();
  _strip.setBrightness(5);
  _strip.show();
}

void Neopixel::loop() {
    uint32_t thisLoop = millis();
    uint32_t dt;
    if (_lastLoop) {
        dt = thisLoop - _lastLoop;
    } else {
        dt = 0;
    }
    _lastLoop = thisLoop;

    if (LIGHTS[_currentIdx] != nullptr) {
        LIGHTS[_currentIdx](dt);
    }
}

void Neopixel::setLight(uint8_t lightIdx) {
  // lightIdx soundIdx. Anything outside of the bounds of the array is 0.
  if (lightIdx >= sizeof(LIGHTS) / sizeof(void*)) {
    lightIdx = 0;
  }

  if (_currentIdx != lightIdx) {
    _strip.clear();
    _strip.show();

    _currentIdx = lightIdx;
  }
}

uint8_t Neopixel::getLight() {
  return _currentIdx;
}

void Neopixel::rainbow(uint32_t dt) {
  static uint8_t offset = 0;
  static uint32_t rainbowColors[NEOPIXEL_COUNT] = {16711680, 13578240, 10444800, 7311360, 4177920, 1044480, 56865, 44625,
                                                   32385, 20145, 7905, 1179885, 4325565, 7471245, 10616925, 13762605};

  if (dt > 50) {
    for (uint8_t pix = 0; pix < NEOPIXEL_COUNT; pix++) {
      _strip.setPixelColor((pix + offset) % NEOPIXEL_COUNT, rainbowColors[pix]);
    }
    _strip.show();
    offset++;
  }
}

// rain_1
void Neopixel::gesture1(uint32_t dt) {
  int counter = 0;
  int light;
  Neopixel::colorWipe(_strip.Color(0, 0, 0), 5);
  if (dt > 50) {
    while (counter < 16) {
      light = rand() % 16;
      uint32_t light_color = _strip.getPixelColor(light);
      if (light_color == 0) {
        counter++;
        _strip.setPixelColor(light, _strip.Color(rand() % 255, rand() % 255, rand() % 255));
        _strip.show();
        delay(150);
      }
    }
  }
}

// blue filling
void Neopixel::gesture2(uint32_t dt) {
  int i, j;
  i = 7;
  j = 8;
  Neopixel::colorWipe(_strip.Color(0, 0, 0), 5);
  int col = 255;
  int counter = 1;
  if (dt > 50) {
    while (i >= 0) {
      _strip.setPixelColor(i, _strip.Color(0, 0, 255));
      _strip.setPixelColor(j, _strip.Color(0, 0, 255));
      _strip.show();
      delay(150);
      _strip.setPixelColor(i, _strip.Color(0, 0, 100));
      _strip.setPixelColor(j, _strip.Color(0, 0, 100));
      _strip.show();
      delay(150);
      i--; j++;
      counter++;
    }
  }
}

// colorful random filling
void Neopixel::gesture3(uint32_t dt) {
  if (dt > 50) {
    for (int i = 0; i < 16; i++) {
      _strip.setPixelColor(i, _strip.Color(rand() & 255, rand() & 255, rand() & 255));
      _strip.show();
      delay(150);
    }
  }
}

// tide
void Neopixel::gesture4(uint32_t dt) {
  if (dt > 50) {
    Neopixel::colorWipe(_strip.Color(30, 70, 200), 5);
    for (int i = 0; i < 6; i++) {
      int delta = rand() % 30;
      int brightness = rand() % 2;
      if (brightness) {
        Neopixel::colorWipe(_strip.Color(30 + delta, 70 + delta, 200 + delta), 5);
      } else {
        Neopixel::colorWipe(_strip.Color(30 - delta, 70 - delta, 200 - delta), 5);
      }
      _strip.show();
      delay(200);
    }
  }
}

// random color filling
void Neopixel::gesture5(uint32_t dt) {
  if (dt > 50) {
    uint32_t randc = _strip.Color(rand() % 255, rand() % 255, rand() % 255);
    for (int i = 0; i < 16; i++) {
      _strip.setPixelColor(i, randc);
    }
    _strip.show();
    delay(150);
  }
}

// unknown_1
void Neopixel::gesture6(uint32_t dt) {
  if (dt > 50) {
    for (int i = 0; i < 255; i += 5) {
      for (int j = 0; j < 16; j++) {
        _strip.setPixelColor(j, i, 255 - i, 100);
      }
      _strip.show();
      delay(150);
    }
  }
}

// unknown_2
void Neopixel::gesture7(uint32_t dt) {
  if (dt > 50) {
    uint32_t bc = _strip.Color(rand()%255, rand()%255, rand()%255);
    uint32_t w = _strip.Color(0, 0, 0);
    Neopixel::colorWipe(bc, 5);
    for (int i = 0; i < 4; i++) {
      uint32_t randc = _strip.Color(rand() % 255, rand() % 255, rand() % 255);
      _strip.setPixelColor(1+i, randc);
      _strip.setPixelColor(5+i, randc);
      _strip.setPixelColor(9+i, randc);
      _strip.setPixelColor(13+i, randc);
      _strip.show();
      delay(150);
      Neopixel::colorWipe(w, 5);
      _strip.show();
    }
  }
}

void Neopixel::flashing(uint8_t dt) {
  if (dt > 50) {
    int wait = 50;
    uint32_t randc = _strip.Color(rand() % 255, rand() % 255, rand() % 255);
    uint32_t white = _strip.Color(255, 255, 255);
    colorAllSet(randc, 40);
    colorAllSet(white, 0);
  }
}

void Neopixel::yellow(uint8_t dt, uint8_t size) {
  _myDelay += dt;
  if (_myDelay > size * 50 || _myDelay < 0) {
    _myDelay = 0;
    uint32_t yellow = _strip.Color(255, 255, 0);
    uint32_t black = _strip.Color(0, 0, 0);
    for (int i = 0; i < size; i++) {
      colorAllSet(yellow, 25);
      colorAllSet(black, 25);
    }
  }
}//

void Neopixel::colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < _strip.numPixels(); i++) {
    _strip.setPixelColor(i, c);
    _strip.show();
    delay(wait);
  }
}

void Neopixel::colorAllSet(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < _strip.numPixels(); i++) {
    _strip.setPixelColor(i, c);
  }
  _strip.show();
  delay(wait);
}

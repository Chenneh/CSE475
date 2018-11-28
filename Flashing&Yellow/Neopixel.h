#ifndef _NEOPIXEL_H_
#define _NEOPIXEL_H_

#include <Adafruit_NeoPixel_ZeroDMA.h>

#define NEOPIXEL_PIN 19
#define NEOPIXEL_COUNT 16

class Neopixel {
 public:
  /** List of all neopixel functions in this class. Each takes dt, the difference in time since the last call. */
  static void rainbow(uint32_t dt);

  static void gesture1(uint32_t dt); // am_3
  static void gesture2(uint32_t dt); // am_1
  static void gesture3(uint32_t dt); // am_2
  static void gesture4(uint32_t dt); // act_3 / am_4
  static void gesture5(uint32_t dt); // act_1
  static void gesture6(uint32_t dt); // act_2
  static void gesture7(uint32_t dt); // start_1 / act_3
  //static void flashing(uint8_t dt); // flashing
  // static void flashing(uint8_t dt);
  // static void yellow(uint8_t dt, uint8_t dur[]);

  /** Array of all light effects, in a fixed order, used to assign an index to each. Add your effects to this! */
  static constexpr void (*LIGHTS[9])(uint32_t) = {nullptr, &rainbow, &gesture1,
                                                         &gesture2, &gesture3,
                                                         &gesture4, &gesture5,
                                                         &gesture6, &gesture7};

  /**
   * Use this to set the current light gesture.
   *
   * @param lightIdx Index of new light effect to play in Neopixel::LIGHTS.
   */
  static void setLight(uint8_t lightIdx);

  /**
   * @returns the index of the current light gesture.
   */
  static uint8_t getLight();

  /** Called to loop whatever the currently selected lighting effect is. */
  static void loop();

  /** Initialize Neopixel. */
  static void setup();

  static void colorWipe(uint32_t c, uint8_t wait);

  static void colorAllSet(uint32_t c, uint8_t wait);
  static void flashing(uint8_t dt);
  static void yellow(uint8_t dt, uint8_t size);

 private:
  /** Current light effect being played. Please do not change this value directly. Use Neopixel::setLight(uint8_t) */
  static uint8_t _currentIdx;

  /** Time since loop was last called. */
  static uint32_t _lastLoop;

  static Adafruit_NeoPixel_ZeroDMA _strip;

  static uint8_t _myDelay;
};

#endif  // _NEOPIXEL_H_

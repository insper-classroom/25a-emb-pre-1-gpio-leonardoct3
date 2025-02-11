#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_LED_R = 4;
const int PIN_LED_G = 6;
const int PIN_BTN_R = 28;
const int PIN_BTN_G = 26;

int main() {
  stdio_init_all();

  gpio_init(PIN_LED_R);
  gpio_init(PIN_LED_G);
  gpio_init(PIN_BTN_R);
  gpio_init(PIN_BTN_G);

  gpio_set_dir(PIN_LED_R, GPIO_OUT);
  gpio_set_dir(PIN_LED_G, GPIO_OUT);

  gpio_set_dir(PIN_BTN_R, GPIO_IN);
  gpio_pull_up(PIN_BTN_R);

  gpio_set_dir(PIN_BTN_G, GPIO_IN);
  gpio_pull_up(PIN_BTN_G);

  while (true) {
    if(!gpio_get(PIN_BTN_R)) {
      if(gpio_get(PIN_LED_R)) {
        gpio_put(PIN_LED_R, 0);
      } else {
        gpio_put(PIN_LED_R, 1);
      }
      
      while (!gpio_get(PIN_BTN_R)){}
    }
    if(!gpio_get(PIN_BTN_G)) {
      if(gpio_get(PIN_LED_G)) {
        gpio_put(PIN_LED_G, 0);
      } else {
        gpio_put(PIN_LED_G, 1);
      }
      while (!gpio_get(PIN_BTN_R)){}
    }
  }
}

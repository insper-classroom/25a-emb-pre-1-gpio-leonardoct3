#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

void debounce() {

}

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    const uint32_t debounceDelay = 30; // 30 milliseconds
    
    int lastReading = 1;
    int buttonState = 1;
    uint32_t lastDebounceTime = 0;
    

    int lastReading2 = 1;
    int buttonState2 = 1;
    uint32_t lastDebounceTime2 = 0;

    while (true) {
        int reading = gpio_get(BTN_PIN);

        if (reading != lastReading) {
            lastDebounceTime = to_ms_since_boot(get_absolute_time());
        }

        if ((to_ms_since_boot(get_absolute_time()) - lastDebounceTime) > debounceDelay) {
            if (reading != buttonState) {
                buttonState = reading;
                if (buttonState == 0) {
                    printf("Botao 1: %d\n", cnt_1++);
                }
            }
        }

        lastReading = reading;

        int reading2 = gpio_get(BTN_PIN_2);

        if (reading2 != lastReading2) {
            lastDebounceTime2 = to_ms_since_boot(get_absolute_time());
        }

        if ((to_ms_since_boot(get_absolute_time()) - lastDebounceTime2) > debounceDelay) {
            if (reading2 != buttonState2) {
                buttonState2 = reading2;
                if (buttonState2 == 0) {
                    printf("Botao 2: %d\n", cnt_2++);
                }
            }
        }

        lastReading2 = reading2;
        
    }
}

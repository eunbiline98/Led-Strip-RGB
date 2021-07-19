#include <PWM.h>

#define RED_LED 3
#define BLUE_LED 5
#define GREEN_LED 5
#define button 8

int btn_mode = 0;
int state = 0;
int btn_status = 0;

int red_state = 0;
int green_state = 0;
int blue_state = 0;
int state_on = 255;

int fadeSpeed = 10;
int32_t frequency = 15000;

void setup() {
  InitTimersSafe();
  SetPinFrequencySafe(RED_LED, frequency);
  SetPinFrequencySafe(GREEN_LED, frequency);
  SetPinFrequencySafe(BLUE_LED, frequency);
}

void led_mode_1() {
  for (int i = 0; i < 256; i++) {
    pwmWrite(RED_LED, red_state);
    red_state += 1;
    delay(fadeSpeed);
  }

  for (int i = 0; i < 256; i++) {
    pwmWrite(BLUE_LED, blue_state);
    blue_state += 1;
    delay(fadeSpeed);
  }

  for (int i = 0; i < 256; i++) {
    pwmWrite(GREEN_LED, green_state);
    green_state += 1;
    delay(fadeSpeed);
  }
}

void led_mode_2() {
  for (int i = 0; i < 256; i++) {
    pwmWrite(GREEN_LED, state_on);
    pwmWrite(RED_LED, state_on);
    pwmWrite(BLUE_LED, state_on);
    state_on -= 1;
    delay(fadeSpeed);
  }
}

void loop() {

  btn_mode = digitalRead(button);
  if (btn_mode == HIGH && state == LOW) {
    Serial.println("Push....");
    btn_status = 1 - btn_status;
  }

  state - btn_mode;

  if (btn_status == HIGH) {
    led_mode_1();
    delay(5000);
    led_mode_2();
  }
  else {
    pwmWrite(RED_LED, 0);
    pwmWrite(GREEN_LED, 0);
    pwmWrite(BLUE_LED, 0);
  }
}

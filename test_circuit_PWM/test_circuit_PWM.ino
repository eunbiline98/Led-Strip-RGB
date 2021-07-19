#include <PWM.h>
int red = 9;
int green = 10;
int blue = 11;

int32_t frequency = 15000;
void setup()
{
  InitTimersSafe();
  SetPinFrequencySafe(red, frequency);
  //  SetPinFrequencySafe(green, frequency);
  //  SetPinFrequencySafe(blue, frequency);

}
void loop()
{
  pwmWrite(red, 225);
  //  pwmWrite(green, 225);
  //  pwmWrite(blue, 225);
  delay(30);
}

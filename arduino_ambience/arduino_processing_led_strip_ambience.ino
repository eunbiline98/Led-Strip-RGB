#include <Adafruit_NeoPixel.h>
#define PIN 6
int countPixel = 12;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(countPixel, PIN, NEO_BRG + NEO_KHZ800);

int r[11];
int g[11];
int b[11];

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {

  if (Serial.available() >= 31) {
    if (Serial.read() == 0xff) {
      for (int i = 0; i < 11; i++) {
        r[i] = Serial.read();
        g[i] = Serial.read();
        b[i] = Serial.read();
      }
    }
  }

  int Xval = 0; 
  int Yval = 1;
  int Zval = 2; 

  for (int z = 0; z < 11; z++) {

    strip.setPixelColor(Xval, r[z], g[z], b[z]);
    strip.setPixelColor(Yval, r[z], g[z], b[z]);
    strip.setPixelColor(Zval, r[z], g[z], b[z]);

    Xval = Xval + 2;
    Yval = Yval + 2;
    Zval = Zval + 2;
  }
  strip.show(); 
  delay(20); 
}

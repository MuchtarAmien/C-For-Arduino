#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
#define SCREEN_ADDRESS 0x3C

void setup() {
Serial.begin(9600);
Serial.println("OLED FeatherWing test");
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
Serial.println(F("SSD1306 allocation failed"));
for(;;); // Don't proceed, loop forever
}

// text display tests
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.clearDisplay();
}

void loop() {
display.setCursor(0,0);
display.print("INDOBOT"); 
display.setCursor(0,20);
display.print("ACADEMY");
display.setCursor(0,40);
display.print("2022");
delay(10);
yield();
display.display();
}

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> //pemanggilan library GFX
#include <Adafruit_SSD1306.h> //pemanggilan library OLED

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

//OLED menggunakan kolom 128 pixel dan baris 64 pixel
#define SCREEN_ADDRESS 0x3C //alamat untuk I2C OLED
#define LDR A0
int bacaLDR = 0;

void setup() {
Serial.begin(9600);
Serial.println("OLED FeatherWing test");
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
{//Memastikan OLED dapat berjalan atau tidak
Serial.println(F("SSD1306 allocation failed"));
for(;;); // Don't proceed, loop forever
}

// text display tests
display.setTextSize(2); //ukuran teks
display.setTextColor(SSD1306_WHITE); //warna OLED (putih)
display.clearDisplay(); //membersihkan display oled
pinMode(LDR,INPUT); //pin untuk input
}

void loop() {
bacaLDR = analogRead(LDR);
display.setCursor(0,0); //menempatkan titik pertama sebelah kanan atas di titik 0,0
display.print(bacaLDR); //menampilan nilai hasil baca LDR

if (bacaLDR >= 500) { //Gelap
display.setCursor(0,25);
display.print("Gelap"); //menampilan tulisan Kondisi gelap
}
else {
display.setCursor(0,25);
display.print("Terang"); //menampilan tulisan Kondisi terang
}
delay(1000);
yield();
display.display();
display.clearDisplay();
}

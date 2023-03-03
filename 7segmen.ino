#include <TM1637Display.h> //Library TM1637
#define CLK D5 //definisi CLK ke pin D5
#define DIO D4 //definisi DIO ke pin D4

int switchUpPin = D7; //membuat switchUpPin pada pin D7
int switchDownPin = D6; //membuat switchDownPin pada pin D6
int counter = 0; //membuat variabel counter
int buttonUpState = 0; //membuat variabel tempat data button up
int buttonDownState = 0; //membuat variabel tempat data button down

TM1637Display display(CLK, DIO); //Pengenalan pin CLK dan DIO

void setup(){
display.setBrightness(0x0f); //Mengatur kecerahan maksimal
pinMode(switchUpPin , INPUT); //mengatur switchUpPin sebagai INPUT
pinMode(switchDownPin, INPUT); //mengatur switchDownPin sebagai INPUT
}

void loop(){
buttonUpState = digitalRead(switchUpPin); //membaca switchUpPin
buttonDownState = digitalRead(switchDownPin); //membaca switchDownPin

if (buttonUpState == HIGH) //jika tombol up ditekan maka
{
if(counter == 9999) { //jika counter bernilai 9999 maka
counter = 0; //counter dikembalikan ke angka 0
}
else { //jika tidak maka
counter++; //nilai counter akan bertambah
}
}
if (buttonDownState == HIGH) //jika tombol down ditekan maka
{
if(counter == 0) { //jika counter bernilai 0 maka
counter = 9999; //counter akan dikembalikan ke angka 9999
}
else {
  counter--; 
}
}
display.showNumberDec(counter); //Menampilkan angka
delay(200); //jeda waktu per pembacaan button (200ms)
}

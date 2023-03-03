const int pinRelay = D8;

void setup() {
Serial.begin(9600);
pinMode(pinRelay, OUTPUT); //kondisi awal relay mati
digitalWrite(pinRelay, HIGH);
}

void loop() {
digitalWrite(pinRelay, LOW);
Serial.println("Relay nyala");
delay(5000); //nyala 1 detik
digitalWrite(pinRelay, HIGH);
Serial.println("Relay mati");
delay(5000); //mati 1 detik
}

int pinBuzzer= D6;

void setup(){
pinMode(pinBuzzer, OUTPUT);
}
void loop(){
digitalWrite(pinBuzzer, HIGH);
delay(100);
digitalWrite(pinBuzzer, LOW);
delay(100);
}

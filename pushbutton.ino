int pinLed1 = D0;
int pinLed2 = D1;
int Button1 = D4;
int Button2 = D5;
void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(Button1, INPUT_PULLUP);
pinMode(Button2, INPUT_PULLUP);

}

void loop() {
int statusBtn1 = digitalRead(Button1);
int statusBtn2 = digitalRead(Button2);
if(statusBtn1 == LOW) {
digitalWrite(pinLed1, HIGH);
}else {
    digitalWrite(pinLed1, LOW);}
if (statusBtn2 == LOW) {
digitalWrite(pinLed2,HIGH );
}else{
  digitalWrite(pinLed2, LOW);
  }
}

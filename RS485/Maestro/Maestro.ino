#include <RS485.h>

const int potPin = A0;
const int buttonPin = 2;
int potValue = 0;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  RS485.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { // Si el botón está presionado
    potValue = analogRead(potPin);
    RS485.beginTransmission();
    RS485.write(potValue / 4); // Convertir a un valor de 8 bits
    RS485.endTransmission();
    delay(100);
  }
}

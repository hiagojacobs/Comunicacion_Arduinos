#include <RS485.h>

int receivedValue = 0;

void setup() {
  RS485.begin(9600);
}

void loop() {
  if (RS485.available()) {
    receivedValue = RS485.read();
    RS485.beginTransmission();
    RS485.write(receivedValue); // Enviar el valor recibido al siguiente Arduino
    RS485.endTransmission();
  }
  delay(100);
}

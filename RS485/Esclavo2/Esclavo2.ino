#include <RS485.h>
#include <Servo.h>

Servo myServo;
int receivedValue = 0;

void setup() {
  myServo.attach(9); // Conectar el servo al pin 9
  RS485.begin(9600);
}

void loop() {
  if (RS485.available()) {
    receivedValue = RS485.read();
    int servoPos = map(receivedValue, 0, 255, 0, 180); // Mapear el valor al ángulo del servo
    myServo.write(servoPos);
  }
  delay(100);
}

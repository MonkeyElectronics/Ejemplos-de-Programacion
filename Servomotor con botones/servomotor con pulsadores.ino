#include <Servo.h>
#define PUL1 2
#define PUL2 3
Servo miservo;
int lec1, lec2, contador, estado1, estado2;
void setup() {
  pinMode(PUL1, INPUT);
  pinMode(PUL2, INPUT);
  Serial.begin(9600);
  miservo.attach(11);
  miservo.write(0);
}

void loop() {
  lec1 = digitalRead(PUL1);
  lec2 = digitalRead(PUL2);
  if (lec1 == 1 && estado1 == 0) {
    delay(200);
    contador = contador + 10;
    miservo.write(contador);
    Serial.println(contador);
  }
  estado1 = lec1;
  if (lec2 == 1 && estado2 == 0) {
    delay(200);
    contador = contador - 10;
    miservo.write(contador);
    Serial.println(contador);
  }
  estado2 = lec2;
}
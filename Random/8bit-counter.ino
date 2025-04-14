/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
*********/

#include <Arduino.h>

#define LED 2
#define output0 23
#define output1 22
#define output2 1
#define output3 3
#define output4 21
#define output5 19
#define output6 18
#define output7 5
byte i;
int pins[8] = {23, 22, 21, 19, 18, 5, 4, 2};
bool bits[8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  /* pinMode(23, OUTPUT); */
  /* pinMode(23, OUTPUT); */
  i = 0;

  for (int j = 0; j < 8; j++) {
    pinMode(pins[j], OUTPUT);
  }
  Serial.println("hello!");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int k = 0; k < 8; k++)  {
    bits[k] = (i >> k) & 0x1;
  }

  for (int k = 0; k < 8; k++) {
    if (bits[k]) {
      digitalWrite(pins[k], HIGH);
      Serial.println("["+ String(i) + "] Led " + String(k) + " is on");
    }
    else {
      digitalWrite(pins[k], LOW);
      /* Serial.println("Led " + String(k) + " is off"); */
    }
  }
  i++;
  delay(100);
}

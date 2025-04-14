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

byte i = 0;
int pins[8] = {23, 22, 21, 19, 18, 5, 4, 2};
bool bits[8];
String input = "";
int r, g, b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for (int j = 0; j < 8; j++) {
    pinMode(pins[j], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.readStringUntil('\n');

    if (input.length() == 7 && input[0] == '#') {
      r = strtol(input.substring(1, 3).c_str(), NULL, 16);
      g = strtol(input.substring(3, 5).c_str(), NULL, 16);
      b = strtol(input.substring(5, 7).c_str(), NULL, 16);

      Serial.print("Parsed RGB: ");
      Serial.print(r); Serial.print(", ");
      Serial.print(g); Serial.print(", ");
      Serial.println(b);

      if (r == 5 && g == 5 && b == 5) {
        for (int k = 0; k < 8; k++) {
          digitalWrite(pins[k], HIGH);
        }
      }
    } else {
      Serial.println("Invalid input");
      for (int k = 0; k < 8; k++) {
        digitalWrite(pins[k], LOW);
      }
    }

      // Optional: flush leftovers
      while (Serial.available()) Serial.read();
    }
  delay(10);

  }


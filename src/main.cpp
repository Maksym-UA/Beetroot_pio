#include <Arduino.h>

#define BUTTON_PIN 17


int16_t counter = 0;

void IRAM_ATTR reaction() {
  counter++;
  Serial.println("\nButton Pressed! Count: " + String(counter));
}



void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), reaction, FALLING);

}

void loop() {
    if (digitalRead(BUTTON_PIN == LOW)) {
        Serial.println("Button pressed!");
        delay(50);

        while(digitalRead(BUTTON_PIN == LOW)){
            delay(10);
        }
    }
    
    Serial.println("Button pressed!");
    delay(150);
}
#include <Arduino.h>

#define LED_PIN_4 4
#define LED_PIN_18 18
#define LED_PIN_19 19

void setup() {
    Serial.begin(9600);
    delay(1000);

    pinMode(BUILTIN_LED, OUTPUT);
    pinMode(LED_PIN_4, OUTPUT);
    pinMode(LED_PIN_18, OUTPUT);
    pinMode(LED_PIN_19, OUTPUT);
}

void turnOnLed(int pin) {
    digitalWrite(pin, HIGH);
    delay(2000); 
    digitalWrite(pin, LOW);
}

void loop() {
    if (Serial.available()) {
        char data = Serial.read();
        ESP_LOGI("UART RECEIVE", "Karakter yang dikirim: %c", data);

        switch (data) {
            case '1':
                ESP_LOGI("LED CONTROL", "Menyalakan LED_BUILTIN");
                turnOnLed(LED_BUILTIN);
                break;
            case '2':
                ESP_LOGI("LED CONTROL", "Menyalakan LED di PIN 4");
                turnOnLed(LED_PIN_4);
                break;
            case '3':
                ESP_LOGI("LED CONTROL", "Menyalakan LED di PIN 18");
                turnOnLed(LED_PIN_18);
                break;
            case '4':
                ESP_LOGI("LED CONTROL", "Menyalakan LED di PIN 19");
                turnOnLed(LED_PIN_19);
                break;
            default:
                ESP_LOGI("LED CONTROL", "Karakter tidak dikenal.");
                break;
        }
    }
}
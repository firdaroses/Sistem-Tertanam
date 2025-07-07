#include <Arduino.h>

#define POT_PIN 15

int adcValue = 0;
float voltage;

void setup() {
    Serial.begin(9600);
}

void loop() {
    adcValue = analogRead(POT_PIN);

    voltage = (adcValue / 4095.0) * 3.3;

    Serial.print("ADC_value: ");
    Serial.print(adcValue);
    Serial.print(" -> voltage: ");
    Serial.println(voltage);
    delay(3000);
}

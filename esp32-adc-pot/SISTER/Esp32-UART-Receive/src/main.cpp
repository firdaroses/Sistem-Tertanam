#include <Arduino.h>

void setup() {
    // Memulai komunikasi serial
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    // Memeriksa jika ada data yang tersedia di Serial
    if (Serial.available()) {
        char data = Serial.read();
        Serial.print("Karakter yang diterima: ");
        Serial.println(data);
    }
}

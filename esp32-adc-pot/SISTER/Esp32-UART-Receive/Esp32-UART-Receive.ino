#include <Arduino.h>

void setup() {
    // Inisialisasi Serial komunikasi dengan baud rate 9600
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    // Cek apakah ada data yang tersedia untuk dibaca dari serial
    if (Serial.available()) {
        char data = Serial.read();  // Membaca satu karakter dari serial
        Serial.print("Karakter yang dikirim: ");
        Serial.println(data);  // Menampilkan karakter yang diterima
    }
}

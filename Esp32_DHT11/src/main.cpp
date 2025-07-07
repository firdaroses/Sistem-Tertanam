#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Definisikan pin dan tipe DHT sensor
#define DHT_PIN 5
#define DHT_TYPE DHT11

// Inisialisasi sensor DHT
DHT dht(DHT_PIN, DHT_TYPE);

float temperature = 0;

void readTemp();

void setup() {
    Serial.begin(9600);
    
    dht.begin();
}

void loop() {
    readTemp();
    
    Serial.print("Temperature DHT11: ");
    Serial.print(temperature);
    Serial.println(" °C");
    
    delay(2000);
}

void readTemp() {
    temperature = dht.readTemperature();

    if (isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    }
}

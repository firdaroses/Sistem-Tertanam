#include <Arduino.h>

volatile bool interruptState = false;
int totalInterruptCounter = 0;  // Inisialisasi counter dengan 0

hw_timer_t* timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL(&timerMux);
    interruptState = true;
    portEXIT_CRITICAL(&timerMux);
}

void setup() {
    // Memulai komunikasi serial
    Serial.begin(9600);

    // Timer initialization
    timer = timerBegin(0, 8000, true);  // clock timer = 80000000 / 8000 = 10000 Hz
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 10000, true);  // Output akhir 10000 / 10000 = 1 Hz -> Periode = 1 s
    timerAlarmEnable(timer);
}

void loop() {
    // Memeriksa jika ada interrupt yang terjadi
    if (interruptState) {
        portENTER_CRITICAL(&timerMux);
        interruptState = false;  // Reset interrupt state
        portEXIT_CRITICAL(&timerMux);

        totalInterruptCounter++;  // Increment counter
        Serial.print("Total interrupt happened: "); // Mengganti ESP_LOGI dengan Serial.println
        Serial.println(totalInterruptCounter);
    }
}

#include <Arduino.h>

volatile bool interruptState = false;
int totalInterruptCounter = 0;

hw_timer_t* timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL(&timerMux);
    interruptState = true;
    portEXIT_CRITICAL(&timerMux);
}

void setup() {
    Serial.begin(9600);

    // Inisialisasi Timer dengan prescaler 80 untuk 1 MHz
     timer = timerBegin(0, 80, true);

    // Menghubungkan fungsi interrupt
    timerAttachInterrupt(timer, &onTimer, true);

    // Mengatur alarm timer untuk setiap 1 detik (1.000.000 ticks)
    timerAlarmWrite(timer, 1000000, true);
    timerAlarmEnable(timer); // Mengaktifkan alarm timer
}

void loop() {
    if (interruptState) {
        portENTER_CRITICAL(&timerMux);
        interruptState = false;
        portEXIT_CRITICAL(&timerMux);

        totalInterruptCounter++;
        Serial.print("Total interrupt happened: ");
        Serial.println(totalInterruptCounter);
    }
}

#include <Arduino.h>
#include "calibration.h"

int normal;

void calibration_run() {
    delay(200);
    normal=analogRead(phototransistor);
    delay(200);   
}

void calibration_flash() {
    int flashes = 0;
    while (flashes < calibration_flashes) {
        digitalWrite(tracerled,HIGH);
        delay(startupflash);
        digitalWrite(tracerled,LOW);
        delay(startupflash);
        flashes++;
    }
}
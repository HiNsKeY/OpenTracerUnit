#include <Arduino.h>
#include "calibration.h"

int normal;

void calibration_run() {
    delay(500);
    normal=analogRead(phototransistor);
    delay(500);   
}

void calibration_flash() {
    digitalWrite(tracerled,HIGH);
    delay(startupflash);
    digitalWrite(tracerled,LOW);
    delay(startupflash);
    digitalWrite(tracerled,HIGH);
    delay(startupflash);
    digitalWrite(tracerled,LOW);
    delay(startupflash);
    digitalWrite(tracerled,HIGH);
    delay(startupflash);
    digitalWrite(tracerled,LOW);
    delay(startupflash);
}
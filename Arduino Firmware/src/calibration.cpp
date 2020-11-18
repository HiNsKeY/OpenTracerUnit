#include <Arduino.h>
#include "calibration.h"

int normal;

void calibration_run() {
    //Flash LEDs at power on
    delay(1000);
    digitalWrite(tracerled,HIGH);
    delay(startupflash);
    digitalWrite(tracerled,LOW);
    delay(startupflash);
    digitalWrite(tracerled,HIGH);
    delay(startupflash);
    digitalWrite(tracerled,LOW);
    delay(startupflash);

    //Set threshhold value
    delay(500);
    normal=analogRead(phototransistor);
    delay(500);

    //Pulse tracer to show calibration successful

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
#include <Arduino.h>
#include "sensor.h"

int output;

void sensor_read() {
    //Read IR sensor phototransistor output and write to variable
    output=analogRead(phototransistor);
}
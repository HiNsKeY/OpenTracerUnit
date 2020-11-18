#include <Arduino.h>
#include "sensor.h"

int output;
bool pulse_enable;

void sensor_read() {
    //Read IR sensor phototransistor output and write to variable
    output=analogRead(phototransistor);
}
void sensor_decision() {
    if ((output<(normal-threshold)) || (output>(normal+threshold)))
    {
        pulse_enable = true;
    }
    else
    {
        pulse_enable = false;
    }
    
    
    
}
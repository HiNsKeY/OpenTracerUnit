#include <Arduino.h>
#include "pulse.h"

void pulse_main() {
    //If output is below threshold pulse tracer
    if ((output<(normal-threshold)) || (output>(normal+threshold)))
    {
        digitalWrite(tracerled,HIGH); //Start tracer LED pulse
        delay(pulselength);
        digitalWrite(tracerled,LOW); //Stop tracer LED pulse
    }
    else
    {}
}
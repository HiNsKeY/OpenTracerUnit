#include <Arduino.h>
#include "pulse.h"
#include "calibration.h"
#include "sensor.h"

int maxpulses = 20;
int pulses = 0;

void pulse_main() {
    if ((pulse_enable == true) && (pulses < maxpulses))
    {
        digitalWrite(tracerled,HIGH); //Start tracer LED pulse
        delay(pulselength);
        digitalWrite(tracerled,LOW); //Stop tracer LED pulse
        pulses++;
    }
    if ((pulse_enable == false) && (pulses < maxpulses))
    {
        digitalWrite(tracerled,LOW); //Stop tracer LED pulse
        pulses = 0;
    }
    
    if (pulses >= maxpulses)
    {
        digitalWrite(tracerled,LOW); //Stop tracer LED pulse
        delay(10);
        calibration_run();
        pulses = 0;
    }
    
}
#include <Arduino.h>

#include "initialisation.h"
#include "calibration.h"

bool diag = false; //Enable Serial output for diag

void setup() { 
    // Start serial monitor ability (DIAG)
    if (diag==true)
    {
        Serial.begin(9600);
    }
    else
    {}
    initialisation_run();
    calibration_run();
}

void loop() {
//Read IR sensor phototransistor output
output=analogRead(phototransistor); 

//Print IR sensor phototransistor value to serial monitor (DIAG)
if (diag==true)
{
    Serial.println(output);
}
else
{}

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

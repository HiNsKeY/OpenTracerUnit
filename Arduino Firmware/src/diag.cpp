#include <Arduino.h>
#include "diag.h"

bool diag = false;

void diag_enable() {
    // Start serial monitor ability (DIAG)
    if (diag==true)
    {
        Serial.begin(9600);
    }
}

void diag_print() {
    //Print IR sensor phototransistor value to serial monitor (DIAG)
if (diag==true)
{
    Serial.println(output);
}
}
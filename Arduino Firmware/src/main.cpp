#include <Arduino.h>

#include "diag.h"
#include "initialisation.h"
#include "calibration.h"
#include "pulse.h"

void setup() { 
    diag_enable();
    initialisation_run();
    calibration_run();
}

void loop() {
    //Read IR sensor phototransistor output
    output=analogRead(phototransistor);

    diag_print();

    pulse_main();

}

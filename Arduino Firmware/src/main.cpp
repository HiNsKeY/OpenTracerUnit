#include <Arduino.h>

#include "diag.h"
#include "initialisation.h"
#include "calibration.h"
#include "sensor.h"
#include "pulse.h"

void setup() { 
    diag_enable();
    initialisation_run();
    startup_flash();
    calibration_run();
    calibration_flash();
}

void loop() {
    sensor_read();
    diag_print();
    sensor_decision();
    pulse_main();
}

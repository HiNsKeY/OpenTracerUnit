#include <Arduino.h>

#include "diag.h"
#include "initialisation.h"
#include "calibration.h"
#include "sensor.h"
#include "pulse.h"

void setup() { 
    diag_enable();
    initialisation_run();
    calibration_run();
}

void loop() {
    sensor_read();
    diag_print();
    pulse_main();

}

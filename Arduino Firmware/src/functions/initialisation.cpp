#include <Arduino.h>
#include "initialisation.h"

void initialisation_run() {
    //Set pin modes
    pinMode(sensorled,OUTPUT);
    pinMode(tracerled,OUTPUT);
    pinMode(phototransistorsupply,OUTPUT);
    pinMode(phototransistor,INPUT);
    //Start digital pins in appropriate states
    digitalWrite(sensorled,HIGH);
    digitalWrite(tracerled,LOW);
    digitalWrite(phototransistorsupply,HIGH);
}

void startup_flash() {
    int flashes = 0;
    delay(1000);
    while (flashes < startup_flashes) {
        digitalWrite(tracerled,HIGH);
        delay(startupflash);
        digitalWrite(tracerled,LOW);
        delay(startupflash);
        flashes++;
    }
}
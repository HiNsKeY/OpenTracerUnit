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
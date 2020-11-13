#include <Arduino.h>

int sensorled = 4; //IR sensor LED pin
int tracerled = 5; //Tracer MOSFET pin
int phototransistorsupply = 15; //IR receiver phototransistor power supply
int phototransistor = A0; //IR receiver phototransistor analog pin
int threshold = 8; //Value at which tracer starts pulse
int pulselength = 5; //Tracer LED pulse length in ms
int startupflash = 100; //Startup flash length

int output; //Value output by analogue phototransistor
int normal; //Normal phototransistor value

bool diag = false; //Enable/disable DIAG mode

void setup() {
//Set pin modes
pinMode(sensorled,OUTPUT);
pinMode(tracerled,OUTPUT);
pinMode(phototransistorsupply,OUTPUT);
pinMode(phototransistor,INPUT);

//Start digital pins in appropriate states
digitalWrite(sensorled,HIGH);
digitalWrite(tracerled,LOW);
digitalWrite(phototransistorsupply,HIGH);

// Start serial monitor ability (DIAG)
if (diag==true)
{
    Serial.begin(9600);
}
else
{
    //Do nothing
}

//Flash LEDs at power on
delay(1000);
digitalWrite(tracerled,HIGH);
delay(startupflash);
digitalWrite(tracerled,LOW);
delay(startupflash);
digitalWrite(tracerled,HIGH);
delay(startupflash);
digitalWrite(tracerled,LOW);
delay(startupflash);

//Set threshhold value
delay(500);
normal=analogRead(phototransistor);
delay(500);

//Pulse tracer to show calibration successful

digitalWrite(tracerled,HIGH);
delay(startupflash);
digitalWrite(tracerled,LOW);
delay(startupflash);
digitalWrite(tracerled,HIGH);
delay(startupflash);
digitalWrite(tracerled,LOW);
delay(startupflash);
digitalWrite(tracerled,HIGH);
delay(startupflash);
digitalWrite(tracerled,LOW);
delay(startupflash);
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
{
    //Do nothing
}

//If output is below threshold pulse tracer
if ((output<(normal-threshold)) || (output>(normal+threshold)))
{
    digitalWrite(tracerled,HIGH); //Start tracer LED pulse
    delay(pulselength);
    digitalWrite(tracerled,LOW); //Stop tracer LED pulse
}
else
{
    //Do nothing
}

}

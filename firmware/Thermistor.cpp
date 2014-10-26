#include "application.h"
#include "Thermistor.h"
#include <math.h>


Thermistor::Thermistor(int pin, int Rn, int R) {
    this->pin = pin;
    nominalR = Rn;
    resistor = (float)R;
}   

        
void Thermistor::begin() {
    pinMode(pin, INPUT);
}       


float Thermistor::getAnalogReadValue() {
    if(NO_OF_SAMPLES == 1) {
        return (float)analogRead(pin);
    }
    int total = 0;
    for(int i=0; i<NO_OF_SAMPLES; i++) {
        total += analogRead(pin); // warning: this can rewind at int limit
        delay(1);
    }

    return (float)total/(float)NO_OF_SAMPLES;
}


float Thermistor::getTempK() {

    float aValue = getAnalogReadValue();
    
    float logRtoRn = log(resistor*(ADC_RANGE/aValue - 1.0)/nominalR);
    float temp = 1.0/(a + b*logRtoRn + c*logRtoRn*logRtoRn + d*pow(logRtoRn,3));
    
    return temp;
}
 
 
float Thermistor::getTempC() {
    return getTempK() - 273.15;
}
 

float Thermistor::getTempF() {
    return 1.8 * getTempK() - 459.67;
}

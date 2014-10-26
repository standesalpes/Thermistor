#define ADC_RANGE 4096.0
#define NO_OF_SAMPLES 10

class Thermistor {
    private:
        float nominalR;
        float resistor;
        int pin;
        int samples = 10;
    
    public:
        Thermistor(int pin, int nominalR, int secondR);
        void begin();
        float getAnalogReadValue();
        float getTempK();
        float getTempC();
        float getTempF();
        float a = 3.3540154E-03;
        float b = 2.5627725E-04;
        float c = 2.0829210E-06;
        float d = 7.3003206E-08;
};

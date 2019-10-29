#include <Arduino.h>
#include <LedLight.h>

using namespace std;
   


    LedLight::LedLight(int pn)
    {
        pinNumber = pn;
        pinMode(pinNumber, OUTPUT);
    } 

    void LedLight::on()
    {
         digitalWrite(pinNumber, HIGH);
    }

    void LedLight::off()
    {
        digitalWrite(pinNumber, LOW);
    }

    void LedLight::blink(int pace)
    {
        digitalWrite(pinNumber, HIGH);
        delay(pace);
        digitalWrite(pinNumber,LOW);
        delay(pace);
    }

   
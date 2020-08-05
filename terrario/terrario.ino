

/*
Sistema de controle do terrário!
https://github.com/TioRACLab/controle-terrario
*/

//#include "pinagem.h"

#include <Wire.h>
//#include "moduloLuz.h"
#include "controleDataHora.h"

struct ts t;

void setup() {
    Serial.begin(9600);
    Wire.begin();


    Serial.println("Init1");
    //initLuz();
    initDataHora();

    Serial.println("Oi Setup");

}

void loop() {
    Serial.println("Loop");

    t = obterDataHora();
    
    Serial.print("Date : ");
    Serial.print(t.mday);
    Serial.print("/");
    Serial.print(t.mon);
    Serial.print("/");
    Serial.print(t.year);
    Serial.print("\t Hour : ");
    Serial.print(t.hour);
    Serial.print(":");
    Serial.print(t.min);
    Serial.print(".");
    Serial.println(t.sec);

    //Serial.println(validarLuz());
    //DS3231_get(&t);
    //validarLuz(&t);
}




#include <Arduino.h>
#include <ds3231.h>
#include "terrario.h"
#include "moduloLuz.h"

void initLuz() {
    Serial.println("Iniciando lampadas...");
    pinMode(pinoLampada, OUTPUT);
}

void validarLuz(struct ts *dataHora, struct Programacao *progLuz) {
    
    digitalWrite(pinoLamapada, (dataHora->sec < 30));
}
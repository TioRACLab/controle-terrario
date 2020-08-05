#include <Arduino.h>

//#include <string.h>
#include <ds3231.h>
#include "moduloLuz.h"

void initLuz() {
    pinMode(pinoLamapada, OUTPUT);
}

//char * validarLuz(struct ts *timestamp) {
String validarLuz() {
    //digitalWrite(pinoLamapada, (timestamp->sec < 30));
    return "Foi!??";
}
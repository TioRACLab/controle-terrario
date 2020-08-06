#include <Arduino.h>
#include <ds3231.h>
#include "pinagem.h"
#include "agenda.h"
#include "moduloLuz.h"

void initLuz() {
    pinMode(pinoLampada, OUTPUT);
}

bool validarLuz(struct ts *dataHora, struct agenda *progLuz) {
    bool valido = progLuz->validar(dataHora, true);
    digitalWrite(pinoLampada, !valido);
    return valido;
}
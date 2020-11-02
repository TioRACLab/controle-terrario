#include <Arduino.h>
#include "pinagem.h"
#include "atmosfera.h"
#include "painel.h"

void initAtmosfesra() {
    pinMode(pinoNeblina, OUTPUT);
    pinMode(pinoArcoIris, OUTPUT);
}

void habilitarNeblina() {
    digitalWrite(pinoArcoIris, HIGH);
    digitalWrite(pinoNeblina, LOW);
}

void habilitarArcoIris() {
    digitalWrite(pinoNeblina, HIGH);
    digitalWrite(pinoArcoIris, LOW);
}

void desabilitarAtmosfera() {
    digitalWrite(pinoNeblina, HIGH);
    digitalWrite(pinoArcoIris, HIGH);
}
#include <Arduino.h>
#include "pinagem.h"
#include "atmosfera.h"

void initAtmosfesra() {
    pinMode(pinoNeblina, OUTPUT);
    pinMode(pinoArcoIris, OUTPUT);
}

void habilitarNeblina() {
    digitalWrite(pinoArcoIris, LOW);
    digitalWrite(pinoNeblina, HIGH);
}

void habilitarArcoIris() {
    digitalWrite(pinoNeblina, LOW);
    digitalWrite(pinoArcoIris, HIGH);
}

void desabilitarAtmosfera() {
    digitalWrite(pinoNeblina, LOW);
    digitalWrite(pinoArcoIris, LOW);
}
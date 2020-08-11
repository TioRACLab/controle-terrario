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

void prepararTesteAtmosfera() {
    digitalWrite(pinoArcoIris, HIGH);
    digitalWrite(pinoNeblina, HIGH);
}

void rodarTesteAtmosfera() {
    trocarMensagem("T: Neblina      ");
    digitalWrite(pinoNeblina, LOW);
    delay(2000);
    digitalWrite(pinoNeblina, HIGH);

    trocarMensagem("T: Arco Iris    ");
    digitalWrite(pinoArcoIris, LOW);
    delay(2000);
    digitalWrite(pinoArcoIris, HIGH);
}
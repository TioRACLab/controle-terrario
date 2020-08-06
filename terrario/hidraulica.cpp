#include "hidraulica.h"
#include "pinagem.h"
#include "agenda.h"
#include <ds3231.h>

void initHidraulica() {
    pinMode(pinoBombaPrincipal, OUTPUT);
    pinMode(pinoCachoeira, OUTPUT);
    pinMode(pinoIrrigacao, OUTPUT);
    pinMode(pinoReservatorio, OUTPUT);
}

void ativarIrrigacao() {
    digitalWrite(pinoCachoeira, LOW);
    digitalWrite(pinoIrrigacao, HIGH);
    digitalWrite(pinoBombaPrincipal, HIGH);
}

void ativarCachoeira() {
    digitalWrite(pinoCachoeira, HIGH);
    digitalWrite(pinoIrrigacao, LOW);
    digitalWrite(pinoBombaPrincipal, HIGH);
}

void desativarBombaPrincipal() {
    digitalWrite(pinoBombaPrincipal, LOW);
    digitalWrite(pinoCachoeira, LOW);
    digitalWrite(pinoIrrigacao, LOW);
}

bool verificarReposicaoAgua() {
    return false;
}

int processarHidraulica(struct ts *dataHora, struct agenda *progIrrigacao, struct agenda *progCachoeira) {
    int estadoHidraulica = 0; // 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água

    if (progIrrigacao->validar(dataHora, false)) {
        Serial.println("Irrigacao ativa.");
        estadoHidraulica = 1;
        ativarIrrigacao();
    }
    else if (progCachoeira->validar(dataHora, true)) {
        Serial.println("Cachoeira ativa.");
        estadoHidraulica = 2;
        ativarCachoeira();
    }
    else {
        Serial.println("Desativar bomba principal");
        desativarBombaPrincipal();
    }

    if (verificarReposicaoAgua())
        estadoHidraulica = 3;

    return estadoHidraulica;
}
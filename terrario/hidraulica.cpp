#include "hidraulica.h"
#include "pinagem.h"
#include "agenda.h"
#include "painel.h"
#include <ds3231.h>

void initHidraulica() {
    pinMode(pinoBombaPrincipal, OUTPUT);
    pinMode(pinoCachoeira, OUTPUT);
    pinMode(pinoIrrigacao, OUTPUT);
    pinMode(pinoReservatorio, OUTPUT);
}

/**
 * Obtem nível da água do lago. 0 = Muito baixo, 1 = Baixo, 2 = Alto
 */
int obterNivelAgua() {
    int valor = analogRead(pinoSensorLago);

    if (valor >= 390)
        return 2;
    
    if (valor >= 300)
        return 1;

    return 0;
}

/**
 * Obtem nível da água do reservatório. True bom, False baixo
 */
bool obterNivelReservatorio() {
    return analogRead(pinoSensorReservatorio) > 900;
}

/**
 * Desativa a bomba principal e as válvulas
 */
void desativarBombaPrincipal() {
    digitalWrite(pinoBombaPrincipal, HIGH);
    digitalWrite(pinoCachoeira, HIGH);
    digitalWrite(pinoIrrigacao, HIGH);
}

/**
 * Ativa a irrigação, se não houver água no lago, desativa tudo.
 */
void ativarIrrigacao() {
    if (obterNivelAgua() >= 1) {
        digitalWrite(pinoCachoeira, HIGH);
        digitalWrite(pinoIrrigacao, LOW);
        digitalWrite(pinoBombaPrincipal, LOW);
    }
    else {
        desativarBombaPrincipal();
    }
}

/**
 * Ativa a cachoeira, se não houver água no lago, desativa tudo.
 */
void ativarCachoeira() {
    if (obterNivelAgua() >= 1) {
        digitalWrite(pinoCachoeira, LOW);
        digitalWrite(pinoIrrigacao, HIGH);
        digitalWrite(pinoBombaPrincipal, LOW);
    }
    else {
        desativarBombaPrincipal();
    }
}

/**
 * Verifica a reposição da água do reservatório para o lago.
 */
bool verificarReposicaoAgua() {
    if (obterNivelAgua() < 2) {
        digitalWrite(pinoReservatorio, LOW);
        return true;
    }
    
    digitalWrite(pinoReservatorio, HIGH);
    return false;
}

/**
 * Verifica o agendamento da irrigação e da cachoeira.
 * 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível
 */
int processarHidraulica(struct ts *dataHora, struct agenda *progIrrigacao, struct agenda *progCachoeira) {
    int estadoHidraulica = 0; // 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível

    if (progIrrigacao->validar(dataHora, false)) {
        estadoHidraulica = 1;
        ativarIrrigacao();
    }
    else if (progCachoeira->validar(dataHora, true)) {
        estadoHidraulica = 2;
        ativarCachoeira();
    }
    else {
        desativarBombaPrincipal();
    }

    if (verificarReposicaoAgua())
        estadoHidraulica = 3;

    if (obterNivelReservatorio())
        estadoHidraulica = -2;

    return estadoHidraulica;
}
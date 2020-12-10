/**
* Módulo de hidráulica, controla cachoeira, reservatório e irrigação.
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "hidraulica.h"
#include "terrarioCentral.h"
#include "programacao.h"
#include "painel.h"
#include <ds3231.h>

/**
 * Inicializa todas as pinagens hidráulica 
 */
void initHidraulica() {
    pinMode(pinoBombaPrincipal, OUTPUT);
    pinMode(pinoCachoeira, OUTPUT);
    pinMode(pinoIrrigacao, OUTPUT);
    pinMode(pinoReservatorio, OUTPUT);

    digitalWrite(pinoBombaPrincipal, HIGH);
    digitalWrite(pinoCachoeira, HIGH);
    digitalWrite(pinoIrrigacao, HIGH);
    digitalWrite(pinoReservatorio, HIGH);
}

/**
 * Obtem nível da água do lago.
 */
void obterNivelLago(uint16_t *status) {
    int valor = analogRead(pinoSensorLago);

    if (valor >= NivelLagoAlto)
        atualizarStatus(status, STS_LAGO_ALTO);
    
    if (valor >= NivelLagoMedio)
        atualizarStatus(status, STS_LAGO_MEDIO);
}

/**
 * Obtem nível da água do reservatório. True bom, False baixo
 */
void obterNivelReservatorio(uint16_t *status) {
    if (analogRead(pinoSensorReservatorio) < NivelReservatorio)
        atualizarStatus(status, STS_RESERVATORIO);
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
    /*if (obterNivelAgua() >= 1) {
        digitalWrite(pinoCachoeira, HIGH);
        digitalWrite(pinoIrrigacao, LOW);
        digitalWrite(pinoBombaPrincipal, LOW);
    }
    else {
        desativarBombaPrincipal();
    }*/
}

/**
 * Ativa a cachoeira, se não houver água no lago, desativa tudo.
 */
void ativarCachoeira() {
    /*if (obterNivelAgua() >= 1) {
        digitalWrite(pinoCachoeira, LOW);
        digitalWrite(pinoIrrigacao, HIGH);
        digitalWrite(pinoBombaPrincipal, LOW);
    }
    else {
        desativarBombaPrincipal();
    }*/
}

/**
 * Verifica a reposição da água do reservatório para o lago.
 */
bool verificarReposicaoAgua() {
    /*if (obterNivelAgua() < 2) {
        digitalWrite(pinoReservatorio, LOW);
        return true;
    }
    
    digitalWrite(pinoReservatorio, HIGH);*/
    return false;
}

/**
 * Verifica o programacaomento da irrigação e da cachoeira.
 * 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível
 */
void processarHidraulica(struct ts *dataHora, uint16_t *status) {
    
    obterNivelLago(status);
    obterNivelReservatorio(status);
    /*int estadoHidraulica = 0; // 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível

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

    return estadoHidraulica;*/
}
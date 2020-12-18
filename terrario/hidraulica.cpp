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

int reservaBaixa = 0;
bool repondoLago = false;

/**
 * Desativa tudo do lago, bomba e válvulas.
 */
void desativarLagoIrrigacao() {
    digitalWrite(pinoBombaPrincipal, HIGH);
    digitalWrite(pinoCachoeira, HIGH);
    digitalWrite(pinoIrrigacao, HIGH);
}

/**
 * Desativa todas as bombas e as válvulas
 */
void desativarHidraulica() {
    desativarLagoIrrigacao();
    digitalWrite(pinoReservatorio, HIGH);
}

/**
 * Inicializa todas as pinagens hidráulica 
 */
void initHidraulica() {
    pinMode(pinoBombaPrincipal, OUTPUT);
    pinMode(pinoCachoeira, OUTPUT);
    pinMode(pinoIrrigacao, OUTPUT);
    pinMode(pinoReservatorio, OUTPUT);

    desativarHidraulica();
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
bool obterNivelReservatorio(uint16_t *status) {
    
    if (analogRead(pinoSensorReservatorio) > NivelReservatorio) {
        reservaBaixa++;

        if (reservaBaixa >= 5) {
            reservaBaixa = 5;
            atualizarStatus(status, STS_RESERVATORIO);
            return false;
        }
    }
    else {
        reservaBaixa = 0;
        return true;
    }
}

/**
 * Verifica a reposição da água do reservatório para o lago.
 * Ativa reposição quando o nível médio não é lido no sensor.
 * Desativa a reposição quando o nível alto é lido no sensor.
 */
void verificarReposicaoAgua(uint16_t *status) {
    if (validarStatus(status, STS_LAGO_ALTO)) {
        repondoLago = false;
        digitalWrite(pinoReservatorio, HIGH);
    }
    else {
        if (repondoLago) {
            digitalWrite(pinoReservatorio, LOW);
            atualizarStatus(status, STS_BOMBA_RESERVATORIO);
        }
        else if (validarStatus(status, STS_LAGO_MEDIO)) {
            digitalWrite(pinoReservatorio, HIGH);
        }
        else {
            repondoLago = true;
            digitalWrite(pinoReservatorio, LOW);
            atualizarStatus(status, STS_BOMBA_RESERVATORIO);
        }
    }
}

/**
 * Ativa a irrigação, se não houver água no lago, desativa tudo.
 */
void verificarIrrigacao(struct ts *dataHora, uint16_t *status) {
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
void verificarCachoeira(uint16_t *status) { 
    if (validarStatus(status, STS_LAGO_MEDIO)) {
        digitalWrite(pinoCachoeira, LOW);
        digitalWrite(pinoBombaPrincipal, LOW);

        atualizarStatus(status, STS_BOMBA_LAGO);
        atualizarStatus(status, STS_CACHOEIRA);
    }
    else {
        if (!validarStatus(status, STS_IRRIGACAO)) {
            digitalWrite(pinoBombaPrincipal, HIGH);    
        }
        
        digitalWrite(pinoCachoeira, HIGH);
    }
}

/**
 * Verifica o programacaomento da irrigação e da cachoeira.
 * 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível
 */
void processarHidraulica(struct ts *dataHora, uint16_t *status) {
    obterNivelLago(status);

    if (obterNivelReservatorio(status)) {
        verificarReposicaoAgua(status);
        verificarIrrigacao(dataHora, status);
        verificarCachoeira(status);
    }
    else {
        desativarHidraulica();
    }
}
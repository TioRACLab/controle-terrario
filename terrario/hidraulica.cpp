/**
* Módulo de hidráulica, controla cachoeira, reservatório e irrigação.
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "hidraulica.h"
#include "terrarioCentral.h"
#include "programacao.h"
#include "painel.h"
#include <ds3231.h>

int reservaBaixa = 0;
bool repondoLago = false;
uint8_t contagemVazio = 0;
uint8_t contagemBaixo = 0;
uint8_t contagemMedio = 0;
uint8_t contagemAlto = 0;
uint8_t statusLago = 0;

/**
 * Desativa tudo do lago, bomba e válvulas.
 */
void desativarLagoIrrigacao() {
    digitalWrite(pinoBombaPrincipal, HIGH);
    digitalWrite(pinoCascata, HIGH);
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
 * Inicializa todo sistema de hidráulica 
 */
void initHidraulica() {
    pinMode(pinoBombaPrincipal, OUTPUT);
    pinMode(pinoCascata, OUTPUT);
    pinMode(pinoIrrigacao, OUTPUT);
    pinMode(pinoReservatorio, OUTPUT);

    desativarHidraulica();
}

/**
 * Obtem nível da água do lago.
 */
void obterNivelLago(uint16_t *status) {
    int valor = analogRead(pinoSensorLago);

    if (valor >= NivelLagoAlto) {
        contagemVazio = 0;
        contagemBaixo = 0;
        contagemMedio = 0;
        contagemAlto++;

        if (contagemAlto > 3) {
            contagemAlto = 0;
            statusLago = 3;
        }
    }
    else if (valor >= NivelLagoMedio) {
        contagemVazio = 0;
        contagemBaixo = 0;
        contagemMedio++;
        contagemAlto = 0;

        if (contagemMedio > 3) {
            contagemMedio = 0;
            statusLago = 2;
        }
    }
    else if (valor >= NivelLagoBaixo) {
        contagemVazio = 0;
        contagemBaixo++;
        contagemMedio = 0;
        contagemAlto = 0;

        if (contagemBaixo > 3) {
            contagemBaixo = 0;
            statusLago = 1;
            atualizarStatus(status, STS_LAGO_NIVEL2);
        }
    }
    else {
        contagemVazio++;
        contagemBaixo = 0;
        contagemMedio = 0;
        contagemAlto = 0;

        if (contagemVazio > 3) {
            contagemVazio = 0;
            statusLago = 0;
        }
    }

    switch (statusLago)
    {
        case 3:
            atualizarStatus(status, STS_LAGO_NIVEL1);
            atualizarStatus(status, STS_LAGO_NIVEL2);
            break;

        case 2:
            atualizarStatus(status, STS_LAGO_NIVEL1);
            break;

        case 1:
            atualizarStatus(status, STS_LAGO_NIVEL2);
            break;
    
        default:
            break;
    }
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
    if (validarStatus(status, STS_LAGO_NIVEL1) && validarStatus(status, STS_LAGO_NIVEL2)) {
        repondoLago = false;
        digitalWrite(pinoReservatorio, HIGH);
    }
    else {
        if (repondoLago) {
            digitalWrite(pinoReservatorio, LOW);
            atualizarStatus(status, STS_BOMBA_RESERVATORIO);
        }
        else if (validarStatus(status, STS_LAGO_NIVEL1)) {
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
 * Processa loop de hidráulica, cerifica o programação da irrigação e da cachoeira, nível do lago e do reservatório.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopHidraulica(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {
    obterNivelLago(status);

    if (obterNivelReservatorio(status)) {
        verificarReposicaoAgua(status);

        if (validarStatus(status, STS_LAGO_NIVEL1) || validarStatus(status, STS_LAGO_NIVEL2)) {
            validarProgramacaoStatus(dataHora, status, statusManual, STS_CASCATA, PROG_CASCATA, false);
            validarProgramacaoStatus(dataHora, status, statusManual, STS_IRRIGACAO, PROG_IRRIGACAO, false);
        }

        if (validarStatus(status, STS_CASCATA) || validarStatus(status, STS_IRRIGACAO)) {
            if (validarStatus(status, STS_CASCATA))
                digitalWrite(pinoCascata, LOW);
            else
                digitalWrite(pinoCascata, HIGH);
            
            if (validarStatus(status, STS_IRRIGACAO))
                digitalWrite(pinoIrrigacao, LOW);
            else
                digitalWrite(pinoIrrigacao, HIGH);

            digitalWrite(pinoBombaPrincipal, LOW);
        }
        else {
            desativarLagoIrrigacao();
        }
    }
    else {
        desativarHidraulica();
    }
}
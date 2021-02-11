/**
* Controle das luzes do terrário.
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include <ds3231.h>
#include "terrarioCentral.h"
#include "programacao.h"
#include "moduloLuz.h"
#include "painel.h"

/**
 * Inicializa o módulo de luzes 
 */
void initLuz() {
    pinMode(pinoLampada, OUTPUT);
    pinMode(pinoLampadaEspectro, OUTPUT);
    pinMode(pinoInterruptorLuz, INPUT); 

    digitalWrite(pinoLampada, HIGH);
    digitalWrite(pinoLampadaEspectro, HIGH);
}

/**
 * Valida se deve ligar ou não a luz natural.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void validarLuzNatural(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {
    if (validarStatus(statusManual, STS_ILUMINACAO)) {
        atualizarStatus(status, STS_ILUMINACAO);
    }
    else {
        int estadoManualLuz = digitalRead(pinoInterruptorLuz);

        if (estadoManualLuz == BOTAO_LUZ_ATIVO) {
            atualizarStatus(status, STS_ILUMINACAO);
        }
        else {
            struct programacao programacaoLuz;
            obterprogramacao(&programacaoLuz, PROG_ILUMINACAO);

            atualizarStatus(status, programacaoLuz.validar(dataHora, true) * STS_ILUMINACAO);
        }
    }

    
}

/**
 * Valida se deve ligar ou não a luz espectro.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void validarLuzEspectro(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {
    if (validarStatus(statusManual, STS_ESPECTRO)) {
        atualizarStatus(status, STS_ESPECTRO);
    }
    else {
        struct programacao programacaoEspectro;
        obterprogramacao(&programacaoEspectro, PROG_ESPECTRO);
        atualizarStatus(status, programacaoEspectro.validar(dataHora, true) * STS_ESPECTRO);
    }
}

/**
 * Valida se deve iniciar o processo de luzes de acordo com a programação
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void validarLuz(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {

    validarLuzNatural(dataHora, status, statusManual);
    validarLuzEspectro(dataHora, status, statusManual);

    digitalWrite(pinoLampada, !validarStatus(status, STS_ILUMINACAO));
    digitalWrite(pinoLampadaEspectro, !validarStatus(status, STS_ESPECTRO));
}
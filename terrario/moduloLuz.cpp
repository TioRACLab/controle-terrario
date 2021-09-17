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

#ifdef MD_LUZ

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
/*void validarLuzNatural(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {
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
}*/


/**
 * Processa loop de luz, valida e liga/desliga de acordo com status manual, programação ou botões.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopLuz(struct ts *dataHora, status *statusAtual, status *statusManual) {

    //validarLuzNatural(dataHora, status, statusManual);
    validarProgramacaoStatus(dataHora, statusAtual, statusManual, STS_ILUMINACAO, PROG_ILUMINACAO, false);
    validarProgramacaoStatus(dataHora, statusAtual, statusManual, STS_ESPECTRO, PROG_ESPECTRO, false);

    digitalWrite(pinoLampada, !validarStatus(statusAtual, STS_ILUMINACAO));
    digitalWrite(pinoLampadaEspectro, !validarStatus(statusAtual, STS_ESPECTRO));
}

#else

void initLuz() { }

void loopLuz(struct ts *dataHora, status *statusAtual, status *statusManual) { }

#endif
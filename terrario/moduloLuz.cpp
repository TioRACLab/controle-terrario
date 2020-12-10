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

int estadoManualLuz = 0;

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
 * Valida se deve iniciar o processo de luzes de acordo com a programação
 */
void validarLuz(struct ts *dataHora, uint16_t *status) {

    estadoManualLuz = digitalRead(pinoInterruptorLuz);

    if (estadoManualLuz == 1) {
        atualizarStatus(status, STS_ILUMINACAO);
    } 
    else {
        struct programacao programacaoLuz;
        obterprogramacao(&programacaoLuz, PROG_ILUMINACAO);

        atualizarStatus(status, programacaoLuz.validar(dataHora, true) * STS_ILUMINACAO);
    }

    struct programacao programacaoEspectro;
    obterprogramacao(&programacaoEspectro, PROG_ESPECTRO);
    atualizarStatus(status, programacaoEspectro.validar(dataHora, true) * STS_ESPECTRO);

    digitalWrite(pinoLampada, validarStatus(status, STS_ILUMINACAO));
    digitalWrite(pinoLampadaEspectro, validarStatus(status, STS_ESPECTRO));
}
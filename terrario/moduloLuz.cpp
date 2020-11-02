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

    digitalWrite(pinoLampada, HIGH);
    digitalWrite(pinoLampadaEspectro, HIGH);
}

/**
 * Valida se deve iniciar o processo de luzes de acordo com a programação
 */
void validarLuz(struct ts *dataHora, uint16_t *status) {
    struct programacao programacaoLuz;
    obterprogramacao(&programacaoLuz, 0);

    atualizarStatus(status, programacaoLuz.validar(dataHora, true) * STS_ILUMINACAO);
    digitalWrite(pinoLampada, validarStatus(status, STS_ILUMINACAO));
}
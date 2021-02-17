/**
* Controle do processa da atmosfera (Trocar para efeitos especiais???)
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "terrarioCentral.h"
#include "atmosfera.h"
#include "painel.h"
#include "programacao.h"


/**
 * Inicializa o módulo de Atmosfesra.
 */
void initAtmosfesra() {
    pinMode(pinoNeblina110v, OUTPUT);
    pinMode(pinoNeblina12v, OUTPUT);

    digitalWrite(pinoNeblina110v, HIGH);
    digitalWrite(pinoNeblina12v, HIGH);
}

/** Processa o loop da atmosfesra, ligando ou desligando itens
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopAtmosfera(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {

    validarProgramacaoStatus(dataHora, status, statusManual, STS_NEBLINA, PROG_NEBLINA, false);

    if (validarStatus(status, STS_NEBLINA)) {
        digitalWrite(pinoNeblina110v, LOW);
        digitalWrite(pinoNeblina12v, LOW);
    }
    else {
        digitalWrite(pinoNeblina110v, HIGH);
        digitalWrite(pinoNeblina12v, HIGH);
    }
}
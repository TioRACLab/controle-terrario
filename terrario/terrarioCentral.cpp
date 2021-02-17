/**
* Definições gerais do terrário 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "programacao.h"
#include "terrarioCentral.h"

/**
 * Valida se o status está valido
 */
bool validarStatus(uint16_t *status, uint16_t valor) {
    return (*status & valor) == valor;
}

/**
 * Atualiza o valor do status adicionando um novo valor
 */
void atualizarStatus(uint16_t *status, uint16_t valor) {
    *status = *status | valor;
}


void validarProgramacaoStatus(struct ts *dataHora, uint16_t *status, uint16_t *statusManual, uint16_t statusValidar, uint8_t programacaoId, bool tempoMinutos) {
    if (validarStatus(statusManual, statusValidar)) {
        atualizarStatus(status, statusValidar);
    }
    else {
        struct programacao programacao;
        obterprogramacao(&programacao, programacaoId);
        atualizarStatus(status, programacao.validar(dataHora, tempoMinutos) * statusValidar);
    }
}
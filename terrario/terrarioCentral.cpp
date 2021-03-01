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
bool validarStatus(status *statusAtual, status valor) {
    return (*statusAtual & valor) == valor;
}

/**
 * Atualiza o valor do status adicionando um novo valor
 */
void atualizarStatus(status *statusAtual, status valor) {
    *statusAtual = *statusAtual | valor;
}


void validarProgramacaoStatus(struct ts *dataHora, status *statusAtual, status *statusManual, status statusValidar, uint8_t programacaoId, bool tempoMinutos) {
    if (validarStatus(statusManual, statusValidar)) {
        atualizarStatus(statusAtual, statusValidar);
    }
    else {
        struct programacao programacao;
        obterprogramacao(&programacao, programacaoId);
        atualizarStatus(statusAtual, programacao.validar(dataHora, tempoMinutos) * statusValidar);
    }
}
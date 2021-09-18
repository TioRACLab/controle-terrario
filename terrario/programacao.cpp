/**
* Módulo de estrutura de programação dos processos
*
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"
#include "programacao.h"
#include "configuracao.h"
#include <ds3231.h>



/**
 * Obtem o tempo em unix a partir de uma estrutura de datetime
 */
/*uint32_t programacao::get_unixtime(struct ts *t) {
    uint16_t y;
    y = t->year - 1600; // cause this is the first year < at 1970 where year % 400 = 0
    return (t->year - 1970) * 31536000 + (t->yday - 1 + (y / 4) - (y / 100) + (y / 400) - 89) * 86400 + t->hour * 3600 + t->min * 60 + t->sec;
}*/

/**
 * Valida se o dia atual é um dia da semana válido
 */
bool programacao::validarDiaSemana(uint8_t diaSemana) {
    return (this->dias && diaSemana) == diaSemana;
}

/**
 * Verifica se a data hora está dentro da programação.
 */
bool programacao::validar(struct ts *dataHora, bool tempoMinutos) {
    //Tipo diario
    if (this->validarDiaSemana(dataHora->wday)) {
        //TODO: Tratar viradas de dia???

        if (dataHora->hour < this->horaInicio || dataHora->hour > this->horaFim) {
            return false;
        }
        
        if (dataHora->hour == this->horaInicio && dataHora->min < this->minutoInicio) {
            return false;
        }

        if (dataHora->hour == this->horaFim && dataHora->min > this->minutoFim) {
            return false;
        }
        
        return true;
    }
    
    return false;
}

/**
 * Obtem a programação desejada
 */
void obterprogramacao(struct programacao *programacao, uint8_t posicao) {
    byte* config = obterConfiguracao();
    uint8_t pos = posicao * 5;

    programacao->dias = config[pos++];
    programacao->horaInicio = config[pos++];
    programacao->minutoInicio = config[pos++];
    programacao->horaFim = config[pos++];
    programacao->minutoFim = config[pos++];
}
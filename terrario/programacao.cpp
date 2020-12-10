/**
* Módulo de estrutura de programação dos processos
*
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "programacao.h"
#include <ds3231.h>

/**
 * Obtem o tempo em unix a partir de uma estrutura de datetime
 */
uint32_t programacao::get_unixtime(struct ts *t)
{
    uint16_t y;
    y = t->year - 1600; // cause this is the first year < at 1970 where year % 400 = 0
    return (t->year - 1970) * 31536000 + (t->yday - 1 + (y / 4) - (y / 100) + (y / 400) - 89) * 86400 + t->hour * 3600 + t->min * 60 + t->sec;
}

/**
 * Verifica se a data hora está dentro da programação.
 */
bool programacao::validar(struct ts *dataHora, bool tempoMinutos) {
    struct ts dataInicio;

    dataInicio.year = dataHora->year;
    dataInicio.mon = dataHora->mon;
    dataInicio.mday = dataHora->mday;
    dataInicio.yday = dataHora->yday;

    //Tipo diario
    if (this->tipo == 1) {
        //TODO: Tratar viradas de dia???

        if (dataHora->hour < this->valor1 || dataHora->hour > this->valor3) {
            return false;
        }
        
        if (dataHora->hour == this->valor1 && dataHora->min < this->valor2) {
            return false;
        }

        if (dataHora->hour == this->valor3 && dataHora->min > this->valor4) {
            return false;
        }
        
        return true;
    }

    //Tipo Semanal
    if (this->tipo ==2) {
        //TODO: Tratar viradas de dia???
        if (dataHora->wday == this->valor1) {
            dataInicio.hour = this->valor2;
            dataInicio.min = this->valor3;

            uint32_t stampInicio = this->get_unixtime(&dataInicio);
            uint32_t stampFim = this->get_unixtime(&dataInicio);
            uint32_t stampAtual = this->get_unixtime(dataHora);

            int16_t segundos = this->valor4;

            if (tempoMinutos)
                segundos = this->valor4 * 60;

            stampFim += segundos;

            return (stampInicio <= stampAtual && stampAtual <= stampFim);
        }

        return false;
    }

    //Automático
    if (this->tipo == 3)
        return true;

    //Tipo de programacao manual e desconhecido.
    return false;
}

/**
 * Obtem a programação desejada
 */
void obterprogramacao(struct programacao *programacao, uint8_t posicao) {
    if (posicao == PROG_ILUMINACAO) {
        programacao->tipo = 1;
        programacao->valor1 = 8;
        programacao->valor2 = 0;
        programacao->valor3 = 18;
        programacao->valor4 = 0;
    }
    else if (posicao == PROG_ESPECTRO) {
        programacao->tipo = 1;
        programacao->valor1 = 8;
        programacao->valor2 = 0;
        programacao->valor3 = 18;
        programacao->valor4 = 0;
    }
}
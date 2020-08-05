#include "programacao.h"
#include <ds3231.h>

uint32_t get_unixtime(struct ts t)
{
    uint16_t y;
    y = t.year - 1600; // cause this is the first year < at 1970 where year % 400 = 0
    return (t.year - 1970) * 31536000 + (t.yday - 1 + (y / 4) - (y / 100) + (y / 400) - 89) * 86400 + t.hour * 3600 + t.min * 60 + t.sec;
}

bool Programacao::validar(struct ts *dataHora, bool tempoMinutos) {

    struct ts dataInicio;

    dataInicio.year = dataHora->year;
    dataInicio.mon = dataHora->mon;
    dataInicio.mday = dataHora->mday;
    dataInicio.yday = dataHora->yday;

    //Tipo diario
    if (this->tipo == 1) {
        //TODO: Tratar viradas de dia???

        if (dataHora->hour < this->valor1 || dataHora->hour > this->valor3)
            return false;
        
        if (dataHora->hour == this->valor1 && dataHora->min < this->valor2)
            return false;

        if (dataHora->hour == this->valor3 && dataHora->min > this->valor4)
            return false;
        
        return true;
    }

    //Tipo Semanal
    if (this->tipo ==2) {
        //TODO: Tratar viradas de dia???
        if (dataHora->wday == this->valor1) {
            dataInicio.hour = this->valor2;
            dataInicio.min = this->valor3;

            uint32_t stampInicio = get_unixtime(dataInicio);
            uint32_t stampFim = get_unixtime(dataInicio);
            uint32_t stampAtual = get_unixtime(*dataHora);

            int16_t segundos = this->valor4;

            if (tempoMinutos)
                segundos = this->valor4 * 60;

            stampFim += segundos;

            return (stampInicio <= stampAtual && stampAtual <= stampFim);
        }

        return false;
    }

    //Tipo de programacao manual e desconhecido.
    return false;
}
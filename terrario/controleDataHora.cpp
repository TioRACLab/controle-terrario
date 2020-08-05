/**
* Módulo de controle de Data Hora para tratamento no terrário
* Esse módulo é responsável em setar e obter valores de data e hora atual.
* Autor: Ricardo Augusto Coelho
* TioRACLAb
*/

#include <ds3231.h>

/**
 * Calcula o dia da semana
 * https://forum.arduino.cc/index.php?topic=443112.0
 * Calculate day of week in proleptic Gregorian calendar. Sunday == 0.
 */
int obterDiaSemana(int year, int month, int day)
{
    int adjustment, mm, yy;
    if (year<2000) year+=2000;
        adjustment = (14 - month) / 12;

    mm = month + 12 * adjustment - 2;
    yy = year - adjustment;
    
    return (day + (13 * mm - 1) / 5 + yy + yy / 4 - yy / 100 + yy / 400) % 7;
}

/**
* Seta a data e hora passada via parâmetros
*/
void setarDataHora(int16_t ano, int8_t mes, int8_t dia, int8_t hora, int8_t minuto, int8_t segundo) {
    struct ts dataHora;

    dataHora.year = ano;
    dataHora.mon = mes;
    dataHora.mday = dia;
    dataHora.hour = hora;
    dataHora.min = minuto;
    dataHora.sec = segundo;

    DS3231_set(dataHora);
}

/**
 * Obtem a data e hora atual 
 */
void obterDataHora(struct ts *dataHora) {
    DS3231_get(dataHora);
    dataHora->wday = obterDiaSemana(dataHora->year, dataHora->mon, dataHora->mday);
}

/**
 * Inicializa sistema de data hora.
 * SDA = 4
 * SCL = 5
 */
void initDataHora(){
    DS3231_init(DS3231_INTCN);

    //TODO: Não setar a data e hota no INIT.
    //setarDataHora(2020, 8, 5, 11, 25, 00);
}

/**
 * Obtem a hora atual e seta uma nova data
 */
void setarData(int16_t ano, int8_t mes, int8_t dia) {
    struct ts dataHora;
    obterDataHora(&dataHora);

    dataHora.year = ano;
    dataHora.mon = mes;
    dataHora.mday = dia;

    DS3231_set(dataHora);
}

/**
 * Obtem a Data atual e seta uma nova hora.
 */
void setarHora(int8_t hora, int8_t minuto, int8_t segundo) {
    struct ts dataHora;
    obterDataHora(&dataHora);

    dataHora.hour = hora;
    dataHora.min = minuto;
    dataHora.sec = segundo;

    DS3231_set(dataHora);
}
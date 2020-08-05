/**
* Módulo de controle de Data Hora para tratamento no terrário
* Esse módulo é responsável em setar e obter valores de data e hora atual.
*/

#include <ds3231.h>

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
struct ts obterDataHora() {
    struct ts dataHora;
    DS3231_get(&dataHora);
    return dataHora;
}

/**
 * Inicializa sistema de data hora.
 * SDA = 4
 * SCL = 5
 */
void initDataHora(){
    DS3231_init(DS3231_INTCN);

    setarDataHora(2020, 8, 4, 20, 34, 12);
}

/**
 * Obtem a hora atual e seta uma nova data
 */
void setarData(int16_t ano, int8_t mes, int8_t dia) {
    struct ts dataHora = obterDataHora();

    dataHora.year = ano;
    dataHora.mon = mes;
    dataHora.mday = dia;

    DS3231_set(dataHora);
}

/**
 * Obtem a Data atual e seta uma nova hora.
 */
void setarHora(int8_t hora, int8_t minuto, int8_t segundo) {
    struct ts dataHora = obterDataHora();

    dataHora.hour = hora;
    dataHora.min = minuto;
    dataHora.sec = segundo;

    DS3231_set(dataHora);
}
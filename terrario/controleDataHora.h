/**
* Módulo de controle de Data Hora para tratamento no terrário
* Esse módulo é responsável em setar e obter valores de data e hora atual.
*
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <ds3231.h>

/**
 * Inicializa sistema de data hora.
 * SDA = 4
 * SCL = 5
 */
void initDataHora();

/**
* Seta a data e hora passada via parâmetros
*/
void setarDataHora(int16_t ano, int8_t mes, int8_t dia, int8_t hora, int8_t minuto, int8_t segundo);

/**
 * Obtem a hora atual e seta uma nova data
 */
void setarData(int16_t ano, int8_t mes, int8_t dia);

/**
 * Obtem a Data atual e seta uma nova hora.
 */
void setarHora(int8_t hora, int8_t minuto, int8_t segundo);

/**
 * Obtem a data e hora atual 
 */
void obterDataHora(struct ts *dataHora);

/**
 * Calcula o dia da semana
 * https://forum.arduino.cc/index.php?topic=443112.0
 * Calculate day of week in proleptic Gregorian calendar. Sunday == 0.
 */
int obterDiaSemana(int year, int month, int day);
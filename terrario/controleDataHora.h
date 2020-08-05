/**
* Módulo de controle de Data Hora para tratamento no terrário
* Esse módulo é responsável em setar e obter valores de data e hora atual.
* Autor: Ricardo Augusto Coelho
* TioRACLAb
*/

#include <ds3231.h>

void initDataHora();

void setarDataHora(int16_t ano, int8_t mes, int8_t dia, int8_t hora, int8_t minuto, int8_t segundo);

void setarData(int16_t ano, int8_t mes, int8_t dia);

void setarHora(int8_t hora, int8_t minuto, int8_t segundo);

void obterDataHora(struct ts *dataHora);

int obterDiaSemana(int year, int month, int day);
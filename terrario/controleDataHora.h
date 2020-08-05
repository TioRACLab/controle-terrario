/*
*
*
*/

#include <Wire.h>
#include <ds3231.h>

void initDataHora();

void setarDataHora(int16_t ano, int8_t mes, int8_t dia, int8_t hora, int8_t minuto, int8_t segundo);

void setarData(int16_t ano, int8_t mes, int8_t dia);

void setarHora(int8_t hora, int8_t minuto, int8_t segundo);

struct ts obterDataHora();
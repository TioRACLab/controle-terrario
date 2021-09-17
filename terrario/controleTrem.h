/**
* Header do módulo dp Trêm
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#ifdef UNO

//Pinos de controle do trenzinho.
#define pinoTrem1 12
#define pinoTrem2 11
#define pinoTremENA 10 //ENA

#elif defined(MEGA)

//Pinos de controle do trenzinho.
#define pinoTrem1 12
#define pinoTrem2 11
#define pinoTremENA 10 //ENA

#endif


void initTrem();

int loopTrem(struct ts *dataHora, status *statusAtual, status *statusManual);
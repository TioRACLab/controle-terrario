/**
* Header do controlador do painel LCD
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

void initSD();

void loopSD(struct ts *dataHora, status *statusAtual, status *statusManual);

void carregarConfiguracao();

void logar(struct ts *dataHora, status *statusAtual, const char mensagem[]);
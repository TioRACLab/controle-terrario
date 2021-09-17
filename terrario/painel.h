/**
* Header do controlador do painel LCD
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#define STS_BOTAO_NULO 0
#define STS_BOTAO_ENTER 1
#define STS_BOTAO_ESQ 2
#define STS_BOTAO_DIR 4

#define pinoBotaoEnter 0
#define pinoBotaoEsq 0
#define pinoBotaoDir 0

/**
 * Inicializa o painel LCD
 */
void initPainel();

/**
 * Atualiza informações mostradas no painel LCD
 */
void loopPainel(struct ts *dataHora, status *statusAtual, status *statusManual);
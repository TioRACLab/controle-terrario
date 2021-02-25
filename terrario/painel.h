/**
* Header do controlador do painel LCD
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#define STS_BOTAO_NULO 0
#define STS_BOTAO_ENTER 1
#define STS_BOTAO_ESQ 2
#define STS_BOTAO_DIR 4

#define pinoBotaoEnter 0
#define pinoBotaoEsq 0
#define pinoBotaoDir 0

typedef void (*painel) (ts*, uint16_t*,  uint16_t*);

/**
 * Inicializa o painel LCD
 */
void initPainel();

/**
 * Atualiza informações mostradas no painel LCD
 */
void loopPainel(struct ts *dataHora, uint16_t *status, uint16_t *statusManual);

/**
 * Mostra data e hora no painel
 */
void mostarPainelIdle(struct ts *dataHora, uint16_t *status, uint16_t *statusManual);
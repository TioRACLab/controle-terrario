/**
* Header do módulo de Atmosfera
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#ifdef UNO

#define pinoNeblina110v 3
#define pinoNeblina12v 2

#elif defined(MEGA)

#define pinoNeblina110v 37
#define pinoNeblina12v 38

#endif

/**
 * Inicializa o módulo de Atmosfesra.
 */
void initAtmosfesra();

/** Processa o loop da atmosfesra, ligando ou desligando itens
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopAtmosfera(struct ts *dataHora, status *statusAtual, status *statusManual);
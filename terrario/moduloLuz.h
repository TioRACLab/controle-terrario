/**
* Header de controle das luzes do terrário. 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#ifdef UNO

#define pinoLampada 9
#define pinoLampadaEspectro 8

#define pinoInterruptorLuz 13

#define BOTAO_LUZ_ATIVO 1

#elif defined(MEGA)

#define pinoLampada 31
#define pinoLampadaEspectro 32

#define pinoInterruptorLuz 13

#define BOTAO_LUZ_ATIVO 0

#endif



/**
 * Inicializa o módulo de luzes 
 */
void initLuz();

/**
 * Processa loop de luz, valida e liga/desliga de acordo com status manual, programação ou botões.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopLuz(struct ts *dataHora, uint16_t *status, uint16_t *statusManual);
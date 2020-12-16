/**
* Header do módulo de hidráulica
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#define NivelLagoAlto 380   //Valor mínimo para identificar o lago como nível alto.
#define NivelLagoMedio 300  //Valor mínimo para identificar o lago como nível médio.
#define NivelReservatorio 950

/**
 * Inicializa todas as pinagens hidráulica 
 */
void initHidraulica();

/**
 * Verifica o programacaomento da irrigação e da cachoeira.
 */
void processarHidraulica(struct ts *dataHora, uint16_t *status);
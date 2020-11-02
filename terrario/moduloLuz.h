/**
* Header de controle das luzes do terrário. 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

/**
 * Inicializa o módulo de luzes 
 */
void initLuz();

/**
 * Valida se deve iniciar o processo de luzes de acordo com a programação
 */
void validarLuz(struct ts *dataHora, uint16_t *status);
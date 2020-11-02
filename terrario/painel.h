/**
* Header do controlador do painel LCD
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

/**
 * Inicializa o painel LCD
 */
void initPainel();

/**
 * Atualiza informações mostradas no painel LCD
 */
void mostrarPainel(struct ts *dataHora, uint16_t *status);
/**
* Header definições gerais do terrário 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

//Define o tipo de board.
//#define UNO     //Board Arduino Uno/Nano
#define MEGA    //Board Arduino Mega


//Status do Terrário

#define STS_DESLIGADO 0             //Tudo desligado.
#define STS_ILUMINACAO 1            //Luz de iluminação ligada.
#define STS_ESPECTRO 2              //Luz de espectro vermleho para as plantas ligadas.
#define STS_LAGO_NIVEL1 4           //Nível 1 do lago. (11 = Alto, 10 = Médio, 01 = Baixo, 00 = Vazio)
#define STS_LAGO_NIVEL2 8           //Nível 2 do lago. (11 = Alto, 10 = Médio, 01 = Baixo, 00 = Vazio)
#define STS_RESERVATORIO 16         //Nível do reservatório baixo.
#define STS_BOMBA_LAGO 32           //Bomba do lago ligada.
#define STS_BOMBA_RESERVATORIO 64   //Bomba do reservatório ligada.
#define STS_CACHOEIRA 128           //Válvula da cachoeira ligada.
#define STS_IRRIGACAO 256           //Válvula da irrigação ligada.
#define STS_NEBLINA 512             //Os nebolizadores estão ligados.
#define STS_ARCOIRIS 1024           //O arco íris está ligado.
#define STS_TREM_FRENTE 2048        //O trêm está andando para frente.
#define STS_TREM_REVERSO 4096       //O três está andando para trás.
#define STS_TREM_LENTO 8192         //Velocidade do trêm é lenta.
#define STS_TREM_MEDIO 16384        //Velocidade do trêm é mediana.
#define STS_TREM_RAPIDO 32768       //Velocidade do trêm é rápido.

/**
 * Valida se o status está valido
 */
bool validarStatus(uint16_t *status, uint16_t valor);

/**
 * Atualiza o valor do status adicionando um novo valor
 */
void atualizarStatus(uint16_t *status, uint16_t valor);

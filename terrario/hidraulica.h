/**
* Header do módulo de hidráulica
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#ifdef UNO

//Reles Hidráulicos
#define pinoBombaPrincipal 7
#define pinoCascata 6
#define pinoIrrigacao 5
#define pinoReservatorio 4

//Pinagens Sensores Hidráulicos
#define pinoSensorLago 21 //A7
#define pinoSensorReservatorio 20 //A6

#elif defined(MEGA)

//Reles Hidráulicos
#define pinoBombaPrincipal 33
#define pinoCascata 34
#define pinoIrrigacao 35
#define pinoReservatorio 36

//Pinagens Sensores Hidráulicos
#define pinoSensorLago 61 //A7
#define pinoSensorReservatorio 60 //A6

#endif


#define NivelLagoAlto 370       //Valor mínimo para identificar o lago como nível alto.
#define NivelLagoMedio 250      //Valor mínimo para identificar o lago como nível médio.
#define NivelLagoBaixo 100      //Valor mínimo para identificar o lago como nível baixo.
#define NivelReservatorio 950

/**
 * Inicializa todo sistema de hidráulica 
 */
void initHidraulica();

/**
 * Processa loop de hidráulica, cerifica o programação da irrigação e da cachoeira, nível do lago e do reservatório.
 * @param dataHora Ponteiro data hora atual do sistema
 * @param status Ponteiro de status atual do sistema.
 * @param statusManual Ponteiro de status desejado do sistema, para ativação de mecanismo manualmente.
 */
void loopHidraulica(struct ts *dataHora, status *statusAtual, status *statusManual);
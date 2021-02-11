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
#define pinoCachoeira 6
#define pinoIrrigacao 5
#define pinoReservatorio 4

//Pinagens Sensores Hidráulicos
#define pinoSensorLago 21 //A7
#define pinoSensorReservatorio 20 //A6

#elif defined(MEGA)

//Reles Hidráulicos
#define pinoBombaPrincipal 33
#define pinoCachoeira 34
#define pinoIrrigacao 35
#define pinoReservatorio 36

//Pinagens Sensores Hidráulicos
#define pinoSensorLago 21 //A7
#define pinoSensorReservatorio 20 //A6

#endif


#define NivelLagoAlto 370   //Valor mínimo para identificar o lago como nível alto.
#define NivelLagoMedio 250  //Valor mínimo para identificar o lago como nível médio.
#define NivelLagoBaixo 100  //Valor mínimo para identificar o lago como nível baixo.
#define NivelReservatorio 950

/**
 * Inicializa todas as pinagens hidráulica 
 */
void initHidraulica();

/**
 * Verifica o programacaomento da irrigação e da cachoeira.
 */
void processarHidraulica(struct ts *dataHora, uint16_t *status);
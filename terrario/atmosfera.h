/**
* Header do módulo de Atmosfera
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#ifdef UNO

#define pinoNeblina 3
#define pinoArcoIris 2

#elif defined(MEGA)

#define pinoNeblina 37
#define pinoArcoIris 38

#endif

void initAtmosfesra();

void habilitarNeblina();

void habilitarArcoIris();

void desabilitarAtmosfera();

void prepararTesteAtmosfera();

void rodarTesteAtmosfera();
/**
* Header do controlador do WiFi
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "terrarioCentral.h"

#define WifiRX 10
#define WifiTX 11
#define WifiSerialSpeed 9600


void initWifi();

void loopWifi(struct ts *dataHora, status *statusAtual, status *statusManual);
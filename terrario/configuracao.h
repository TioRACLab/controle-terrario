/**
* Header de configuração
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>

/**
 * Obtem a configuração atual do sistema
 */
byte* obterConfiguracao();

String obterWifiSSID();

String obterWifiSenha();

void setarWifiSSID(String ssid);

void setarWifiSenha(String senha);
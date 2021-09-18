/**
* Configuração
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "configuracao.h"

byte config[25];
String wifi_ssid = "";
String wifi_senha = "";

/**
 * Obtem a configuração atual do sistema
 */
byte* obterConfiguracao() {
    return config;
}

String obterWifiSSID() {
    return wifi_ssid;
}

String obterWifiSenha() {
    return wifi_senha;
}

void setarWifiSSID(String ssid) {
    wifi_ssid = ssid;
}

void setarWifiSenha(String senha) {
    wifi_senha = senha;
}
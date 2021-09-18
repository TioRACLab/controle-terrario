/**
* 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "wifi.h"
#include "terrarioCentral.h"


#ifdef MD_WIFI

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "configuracao.h"

SoftwareSerial wifiSerial(WifiRX, WifiTX);
uint8_t wifiStatus = 0;
char ipd[] = "+IPD,";

void initWifi() { 
    wifiSerial.begin(WifiSerialSpeed);
}

void configurarWiFi() {
    String response = "";

    while (wifiSerial.available()) {
        //Obter resposta do Wi-Fi
        response += (char)wifiSerial.read();
    }

    if (wifiStatus == 0) {
        //Iniciar configuração com Wi-Fi.
        wifiSerial.print("AT+CWMODE=1\r\n");
        wifiStatus = 1;
        //Serial.print("AT+CWMODE=1\r\n");
    }
    else if (wifiStatus == 1 && (response.indexOf("no change") > 0 || response.indexOf("OK") > 0)) {
        //Configura SSID e Senha do Wi-Fi.
        String configWifi = "AT+CWJAP=\"";
        configWifi.concat(obterWifiSSID());
        configWifi.concat("\",\"");
        configWifi.concat(obterWifiSenha());
        configWifi.concat("\"\r\n");

        wifiSerial.print(configWifi);
        //Serial.print(configWifi);
        wifiStatus = 2;
    }
    else if (wifiStatus == 2) {
        // Verifica se já tem IP.
        wifiSerial.print("AT+CIFSR\r\n");
        //Serial.print("AT+CIFSR\r\n");
        wifiStatus = 3;
    }
    else if (wifiStatus == 3 && response.indexOf("busy p") >= 0) {
        // Ainda está procurando e conectando no Wi-Fi, volta um passo.
        wifiStatus = 2;
    }
    else if (wifiStatus == 3 && response.indexOf("0.0.0.0") >= 0) {
        // Rede Wi-Fi não conectada. Tenta novamente.
        wifiStatus = 1;
    }
    else if (wifiStatus == 3 
                && response.length() > 0 
                && response.indexOf(".") > 0) {
        // Obteve um IP, habilitar múltiplas conexões.
        Serial.print(response);
        wifiSerial.print("AT+CIPMUX=1\r\n");
        wifiStatus = 4;
    }
    else if (wifiStatus == 4 && response.length() > 0) {
        // Habilita server na porta 80.
        wifiSerial.print("AT+CIPSERVER=1,80\r\n");
        //Serial.print("AT+CIPSERVER=1,80\r\n");
        wifiStatus = 5;
    }
    else if (wifiStatus == 5 && response.length() > 0) {
        // Wi-Fi configurado e conectado, muda para status de processamento.
        wifiStatus = 100;
        Serial.println("Wi-fi conectado com sucesso!");
    }
}


void verificarRequests(struct ts *dataHora, status *statusAtual, status *statusManual) {

    if (wifiSerial.available() && wifiSerial.find(ipd)) {
        delay(300);
        int connectionId = wifiSerial.read() - 48;
        String response = "";

        while (wifiSerial.available()) {
            response += (char)wifiSerial.read();
        }

        String webpage = "{";
        webpage += "\"status\": ";
        webpage += *statusAtual;
        webpage += "}";
    
        String cipSend = "AT+CIPSEND=";
        cipSend += connectionId;
        cipSend += ",";
        cipSend += webpage.length();
        cipSend += "\r\n";

        wifiSerial.print(cipSend);
        delay(300);
        wifiSerial.print(webpage);
        delay(300);

        String closeCommand = "AT+CIPCLOSE=";
        closeCommand += connectionId;
        closeCommand += "\r\n";

        wifiSerial.print(closeCommand);
    }
}

void loopWifi(struct ts *dataHora, status *statusAtual, status *statusManual) { 
    if (wifiStatus < 100) {
        configurarWiFi();
    }
    else {
        verificarRequests(dataHora, statusAtual, statusManual);
    }
}

#else

void initWifi() { }

void loopWifi(struct ts *dataHora, status *statusAtual, status *statusManual) { }

#endif
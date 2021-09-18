/**
* Header definições gerais do terrário 
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "sd.h"
#include "terrarioCentral.h"

#ifdef MD_SD

#include <SPI.h>
#include <SD.h>
#include <ds3231.h>
#include "configuracao.h"

File logFile;
bool sdOk = false;
status ultimoStatus = 0;

String obtemString(File configFile) {
    String response = "";
    uint8_t tamanho = configFile.read();

    for (uint8_t i = 0; i < tamanho; i++)
    {
        if (configFile.available()) {
            response += (char)configFile.read();
        }
    }

    return response;
}

void carregarConfiguracao() {
    File configFile = SD.open("terrario.bin");
    byte* config = obterConfiguracao();

    if (configFile.available() && configFile.size() >= 25) {
        configFile.read(config, 25);
    }

    setarWifiSSID(obtemString(configFile));
    setarWifiSenha(obtemString(configFile));

    configFile.close();
}

void initSD() {
    if (SD.begin()) {
        carregarConfiguracao();
        logFile = SD.open("terrario.csv", FILE_WRITE);
        sdOk = true;
    }
}

void loopSD(struct ts *dataHora, status *statusAtual, status *statusManual) {
    if (*statusAtual != ultimoStatus) {
        logar(dataHora, statusAtual, "Status Alterado");
        ultimoStatus = *statusAtual;
    }
}

void escreverDatahora(struct ts *dataHora) {
    logFile.print(dataHora->year);
    logFile.print("-");

    if (dataHora->mon <= 9)
        logFile.print(0);
    
    logFile.print(dataHora->mon);
    logFile.print("-");

    if (dataHora->mday <= 9)
        logFile.print(0);
    logFile.print(dataHora->mday);

    logFile.print(",");
    if (dataHora->hour <= 9)
        logFile.print(0);
    logFile.print(dataHora->hour);
    
    logFile.print(":");
    if (dataHora->min <= 9)
        logFile.print(0);
    logFile.print(dataHora->min);
    
    logFile.print(":");
    if (dataHora->sec <= 9)
        logFile.print(0);
    logFile.print(dataHora->sec);
}

void escreverStatus(status *statusAtual) {
    logFile.print(validarStatus(statusAtual, STS_ILUMINACAO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_ESPECTRO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_LAGO_NIVEL1));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_LAGO_NIVEL2));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_RESERVATORIO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_BOMBA_LAGO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_BOMBA_RESERVATORIO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_CASCATA));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_IRRIGACAO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_NEBLINA));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_ARCOIRIS));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_TREM_FRENTE));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_TREM_REVERSO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_TREM_LENTO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_TREM_MEDIO));
    logFile.print(",");

    logFile.print(validarStatus(statusAtual, STS_TREM_RAPIDO));
}

void logar(struct ts *dataHora, status *statusAtual, const char mensagem[]) {
    escreverDatahora(dataHora);
    logFile.print(",");
    escreverStatus(statusAtual);
    logFile.print(",");
    logFile.print(mensagem);
    logFile.print("\r\n");
    logFile.flush();
}

#else

void initSD() {}

void loopSD(struct ts *dataHora, status *statusAtual, status *statusManual) {}

void carregarConfiguracao() {}

void logar(struct ts *dataHora, status *statusAtual, const char mensagem[]) {}

#endif
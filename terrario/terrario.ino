/*
* Sistema de controle do terrário!
* https://github.com/TioRACLab/controle-terrario
*/


#include <Wire.h>

#include "pinagem.h"
#include "controleDataHora.h"
#include "moduloLuz.h"
#include "agenda.h"
#include "painel.h"
#include "hidraulica.h"
#include "controleTrem.h"
#include "atmosfera.h"

void setup() {

    initLuz();

    Serial.begin(9600);
    Serial.println("Sistema do terrario está iniciando");

    Wire.begin();

    initDataHora();
    //setarDataHora(2020, 10, 31, 14, 48, 00);

    
    initPainel();
    /*initHidraulica();
    initTrem();
    initAtmosfesra();*/

    //pinMode(pinoBotao, INPUT);

    Serial.println("Terrario configurado");
}

void loop() {
    uint16_t status = STS_DESLIGADO;
    struct ts dataHora;
    
    //struct agenda progC;
    //progC.tipo = 3;

    obterDataHora(&dataHora);
    
    validarLuz(&dataHora, &status);
    /*int statusHidraulica = processarHidraulica(&dataHora, &prog, &progC);
    processarTrem(&dataHora, &prog);*/
    //TODO: Atmosfera

    //int valor = analogRead(pinoSensorLago);


    mostrarPainel(&dataHora, &status);
}
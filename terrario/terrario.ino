/**
* Sistema de controle do terrário!
* 
* Autor: Ricardo Augusto Coelho
* TioRACLAb
*
* Site: https://tioraclab.com
* https://github.com/TioRACLab/controle-terrario
*/

#include <Wire.h>
#include "terrarioCentral.h"
#include "controleDataHora.h"
#include "moduloLuz.h"
#include "programacao.h"
#include "painel.h"
#include "hidraulica.h"
#include "controleTrem.h"
#include "atmosfera.h"

/**
 * Inicializar sistema de terrário, configurações de pinagens
 */
void setup() {

    initLuz();
    initHidraulica();
    /*
    initTrem();
    initAtmosfesra();*/

    Serial.begin(9600);
    Serial.println("Sistema do terrario está iniciando");

    Wire.begin();

    initDataHora();
    //setarDataHora(2020, 10, 31, 14, 48, 00);

    initPainel();

    Serial.println("Terrario configurado");

    delay(3000); //Proteção de energia interrupta
}

/**
 * Looping principal da programação do terrário
 */
void loop() {
    uint16_t status = STS_DESLIGADO;
    struct ts dataHora;
    
    //struct programacao progC;
    //progC.tipo = 3;

    obterDataHora(&dataHora);
    
    validarLuz(&dataHora, &status);
    /*int statusHidraulica = processarHidraulica(&dataHora, &prog, &progC);
    processarTrem(&dataHora, &prog);*/
    //TODO: Atmosfera

    //int valor = analogRead(pinoSensorLago);


    mostrarPainel(&dataHora, &status);
}
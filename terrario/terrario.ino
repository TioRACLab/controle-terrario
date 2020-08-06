


/*
Sistema de controle do terrário!
https://github.com/TioRACLab/controle-terrario
*/


#include <Wire.h>

#include "pinagem.h"
#include "controleDataHora.h"
#include "moduloLuz.h"
#include "agenda.h"
#include "painel.h"
#include "hidraulica.h"

struct agenda prog;

void setup() {
    Serial.begin(9600);
    Serial.println("Sistema do terrario está iniciando");

    Wire.begin();

    initDataHora();
    setarDataHora(2020, 8, 5, 18, 32, 00);

    initLuz();
    initPainel();
    initHidraulica();

    Serial.println("Terrario configurado");
}

void loop() {
    //Serial.println("Loop");

    struct ts dataHora;
    struct agenda prog;

    prog.tipo = 1;
    prog.valor1 = 12;
    prog.valor2 = 0;
    prog.valor3 = 18;
    prog.valor4 = 0;

    struct agenda progC;

    progC.tipo = 3;

    obterDataHora(&dataHora);
    validarLuz(&dataHora, &prog);
    processarHidraulica(&dataHora, &prog, &progC);

    mostrarPainel(&dataHora, "Estamos evoluindo!!!");
    
    
    //Serial.println(validarLuz());
    //DS3231_get(&t);
    //validarLuz(&t);
}

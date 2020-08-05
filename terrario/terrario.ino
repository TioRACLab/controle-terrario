

/*
Sistema de controle do terrário!
https://github.com/TioRACLab/controle-terrario
*/


#include <Wire.h>

#include "terrario.h"
#include "controleDataHora.h"
//#include "moduloLuz.h"
#include "programacao.h"

struct Programacao prog;

void setup() {
    Serial.begin(9600);
    Serial.println("Sistema do terrario está iniciando");

    Wire.begin();

    initDataHora();
    //initLuz();

    Serial.println("Terrario configurado");

    prog.tipo = 2;
    prog.valor1 = 3;
    prog.valor2 = 10;
    prog.valor3 = 25;
    prog.valor4 = 10;
}

void loop() {
    Serial.println("Loop");

    struct ts dataHora;
    obterDataHora(&dataHora);

    bool valor = prog.validar(&dataHora, false);
    Serial.println(valor);


    //validarLuz(&dataHora);
    
    
    //Serial.println(validarLuz());
    //DS3231_get(&t);
    //validarLuz(&t);
}

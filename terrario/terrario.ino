

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

    prog.tipo = 1;
    prog.valor1 = 1;
    prog.valor2 = 0;
    prog.valor3 = 3;
    prog.valor4 = 4;
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

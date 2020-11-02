/**
* Controle do painel de LCD
* 
* Autor: Ricardo Augusto Coelho
* TioRACLAb
*/

#include <Arduino.h>
#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal_I2C.h>

#include "painel.h"
#include "pinagem.h"

LiquidCrystal_I2C lcd(0x27,20,4);

void initPainel() {
    lcd.init();
    lcd.backlight();
}

bool validarStatus(uint16_t *status, uint16_t valor) {
    return (*status & valor) == valor;
}

void mostrarDatahora(struct ts *dataHora) {
    lcd.setCursor(0,0);

    if (dataHora->mday <= 9)
        lcd.print(0);
    lcd.print(dataHora->mday);

    lcd.print("/");
    if (dataHora->mon <= 9)
        lcd.print(0);
    lcd.print(dataHora->mon);

    lcd.print("/");
    lcd.print(dataHora->year);

    lcd.print(" ");
    if (dataHora->hour <= 9)
        lcd.print(0);
    lcd.print(dataHora->hour);
    
    lcd.print(":");
    if (dataHora->min <= 9)
        lcd.print(0);
    lcd.print(dataHora->min);
}

void mostrarMensagem(uint16_t *status) {
    lcd.setCursor(0,1);
    
    if (validarStatus(status, STS_ILUMINACAO)) {
        lcd.print("Luz: Ligada");
    }
    else {
        lcd.print("Luz: Apagada");
    }
}

void mostrarPainel(struct ts *dataHora, uint16_t *status) {
    mostrarDatahora(dataHora);
    mostrarMensagem(status);
}
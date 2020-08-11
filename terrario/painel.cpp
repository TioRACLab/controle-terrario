#include "painel.h"
#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void initPainel() {
    lcd.init();
}

void trocarMensagem(const char* mensagem) {
    lcd.setCursor(0,1);
    lcd.print(mensagem);
}

void mostrarPainel(struct ts *dataHora, const char* mensagem) {
    lcd.backlight();
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

    trocarMensagem(mensagem);
}
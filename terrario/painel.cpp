/**
* Controle do painel de LCD
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal_I2C.h>

#include "painel.h"
#include "terrarioCentral.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

/**
 * Inicializa o painel LCD
 */
void initPainel() {
    lcd.init();
    lcd.backlight();
}

/**
 * Mostra data e hora atual na primeira linha do LCD
 * @param dataHora Data hora atual para mostrar na primeira linha do monitor LCD
 */
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

/**
 * Mostra mensagem do status na segunda linha do LCD
 * @param status Status atual do terrário para mostrar a mensagem ideal na segunda linha
 */
void mostrarMensagem(uint16_t *status) {
    lcd.setCursor(0,1);
    
    if (validarStatus(status, STS_RESERVATORIO)) {
        lcd.print(" Reserva Baixa! ");
    }
    else if (validarStatus(status, STS_BOMBA_RESERVATORIO)) {
        lcd.print("  Repondo Lago  ");
    }
    else if (validarStatus(status, STS_IRRIGACAO)) {
        lcd.print("  Irrigando...  ");
    }
    else if (validarStatus(status, STS_ILUMINACAO)) {
        lcd.print("    BOM DIA!    ");
    }
    else if (validarStatus(status, STS_ESPECTRO)) {
        lcd.print("    PENUMBRA    ");
    }
    else {
        lcd.print("   BOA NOITE!   ");
    }    
}

/**
 * Atualiza informações mostradas no painel LCD
 */
void mostrarPainel(struct ts *dataHora, uint16_t *status) {
    mostrarDatahora(dataHora);
    mostrarMensagem(status);
}
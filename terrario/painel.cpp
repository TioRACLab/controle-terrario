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
painel processo = &mostarPainelIdle;

String titulo = String("");
String opcoes[10] = {};
uint8_t qtdOpcoes = -1;
uint8_t opcaoAtual = -1;

uint8_t statusBotoes = 0;
uint8_t botaoAtual = 0;

void escreverLinhaLCD(String str, bool voltar = false, bool avancar = false) {
    int start = (16 - str.length()) / 2;
    int end = str.length() + start;
    String text = String("");

    for (uint16_t i = 0; i < 16; i++)
    {
        if (i == 0 && voltar) 
            text += "<";
        else if (i == 15 && avancar)
            text += ">";
        else if (i < start || i >= end)
            text += " ";
        else
            text += str[i - start];
    }

    lcd.print(text);
}

void mostrarPainelOpcoes(struct ts *dataHora, status *statusAtual, status *statusManual);

/**
 * Inicializa o painel LCD
 */
void initPainel() {
    lcd.init();
    lcd.backlight();

    /*titulo = String("Titulo");
    qtdOpcoes = 0;
    opcaoAtual = 0;
    opcoes[opcaoAtual] = String("Gatinha!");
    processo = &mostrarPainelOpcoes;*/
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
void mostrarMensagem(status *statusAtual) {
    lcd.setCursor(0,1);
    
    if (validarStatus(statusAtual, STS_RESERVATORIO)) {
        lcd.print(" Reserva Baixa! ");
    }
    else if (validarStatus(statusAtual, STS_BOMBA_RESERVATORIO)) {
        lcd.print("  Repondo Lago  ");
    }
    else if (validarStatus(statusAtual, STS_IRRIGACAO)) {
        lcd.print("  Irrigando...  ");
    }
    else if (validarStatus(statusAtual, STS_ILUMINACAO)) {
        lcd.print("    BOM DIA!    ");
    }
    else if (validarStatus(statusAtual, STS_ESPECTRO)) {
        lcd.print("    PENUMBRA    ");
    }
    else {
        lcd.print("   BOA NOITE!   ");
    }    
}

/**
 * Mostra data e hora no painel
 */
void mostarPainelIdle(struct ts *dataHora, status *statusAtual, status *statusManual) {
    mostrarDatahora(dataHora);
    mostrarMensagem(statusAtual);
}

void mostrarPainelOpcoes(struct ts *dataHora, status *statusAtual, status *statusManual) {
    lcd.setCursor(0,0);

    uint8_t diff = 16 - titulo.length();

    escreverLinhaLCD(titulo);
    lcd.setCursor(0,1);
    escreverLinhaLCD(opcoes[opcaoAtual], true, true);
}

/*void validarBotao(uint8_t pino, uint8_t statusBotoes) {
    bool statusAtual = (statusBotoes & statusAtual) == statusAtual;

    if (digitalRead(pino)) {
        if (!statusAtual) {
            statusBotoes = statusBotoes | statusAtual;
            botaoAtual = statusAtual;
        }
    }
    else if (statusAtual) {
        statusBotoes = statusBotoes ^ statusAtual;
    }
}*/

/**
 * Atualiza informações mostradas no painel LCD
 */
void loopPainel(struct ts *dataHora, status *statusAtual, status *statusManual) {
    processo(dataHora, statusAtual, statusManual);
}

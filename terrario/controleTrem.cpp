#include <ds3231.h>
#include "agenda.h"
#include "pinagem.h"
#include "controleTrem.h"
#include "painel.h"


void initTrem() {
    pinMode(pinoTrem1, OUTPUT);
    pinMode(pinoTrem2, OUTPUT);
    pinMode(pinoTremENA, OUTPUT);

    // Set PWM frequency for D9 & D10
    TCCR1B = TCCR1B & B11111000 | B00000100;    
}

void movimentar(bool frente, int velocidade) {
    digitalWrite(pinoTrem1, frente ? LOW : HIGH);
    digitalWrite(pinoTrem2, frente ? HIGH : LOW);
    
    if (velocidade > 255)
        velocidade = 255;
    
    analogWrite(pinoTremENA, velocidade);
}

void pararTrem() {
    digitalWrite(pinoTrem1, HIGH);
    digitalWrite(pinoTrem2, HIGH);
    analogWrite(pinoTremENA, 0);
}

int processarTrem(struct ts *dataHora, struct agenda *prog) {
    if (prog->validar(dataHora, true)) {
        movimentar(true, 255);
    }
    else if (prog->tipo != 0) {
        pararTrem();
    }
}

void prepararTesteTrem() {
    pararTrem();
}

void rodarTesteTrem() {
    trocarMensagem("T: Trem F 100%  ");
    movimentar(true, 255);
    delay(2000);
    pararTrem();

    delay(10);
    trocarMensagem("T: Trem F 50%  ");
    movimentar(true, 127);
    delay(2000);
    pararTrem();

    delay(10);
    trocarMensagem("T: Trem Re 50%  ");
    movimentar(false, 127);
    delay(2000);
    pararTrem();

    delay(10);
    trocarMensagem("T: Trem Re 100% ");
    movimentar(false, 255);
    delay(1000);
    pararTrem();
}
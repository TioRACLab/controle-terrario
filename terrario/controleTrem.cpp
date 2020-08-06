#include <ds3231.h>
#include "agenda.h"
#include "pinagem.h"
#include "controleTrem.h"


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

void parar() {
    digitalWrite(pinoTrem1, HIGH);
    digitalWrite(pinoTrem2, HIGH);
    analogWrite(pinoTremENA, 0);
}

int processarTrem(struct ts *dataHora, struct agenda *prog) {
    if (prog->validar(dataHora, true)) {
        movimentar(true, 255);
    }
    else if (prog->tipo != 0) {
        parar();
    }
}
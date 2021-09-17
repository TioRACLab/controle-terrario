/**
* Header do módulo dp Trêm
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "controleTrem.h"
#include "terrarioCentral.h"


#ifdef MD_TREM

#include <ds3231.h>
#include "programacao.h"


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

#else

void initTrem() { }

#endif

int loopTrem(struct ts *dataHora, status *statusAtual, status *statusManual) { }


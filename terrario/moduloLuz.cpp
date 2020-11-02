#include <Arduino.h>
#include <ds3231.h>
#include "pinagem.h"
#include "agenda.h"
#include "moduloLuz.h"
#include "painel.h"

void initLuz() {
    pinMode(pinoLampada, OUTPUT);
    pinMode(pinoLampadaEspectro, OUTPUT);

    digitalWrite(pinoLampada, HIGH);
    digitalWrite(pinoLampadaEspectro, HIGH);
}

void validarLuz(struct ts *dataHora, uint16_t *status) {
    struct agenda agendaLuz;
    obterAgenda(&agendaLuz, 0);

    *status = *status | (agendaLuz.validar(dataHora, true) * STS_ILUMINACAO);
    digitalWrite(pinoLampada, (*status & STS_ILUMINACAO) != STS_ILUMINACAO);
}
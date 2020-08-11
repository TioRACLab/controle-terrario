
void initHidraulica();

/**
 * Verifica o agendamento da irrigação e da cachoeira.
 * 0 = Tudo desativado, 1 = Irrigacao, 2 = Cachoeira, 3 = Repondo água, -1 = Lago em baixo nível, -2 = Reservatório baixo nível
 */
int processarHidraulica(struct ts *dataHora, struct agenda *progIrrigacao, struct agenda *progCachoeira);

void prepararHidraulica();

void rodarTesteHidraulica();
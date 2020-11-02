/**
* Módulo de estrutura de programação dos processos
* Autor: Ricardo Augusto Coelho
* TioRACLAb
*/


#include <Arduino.h>

/**
 * Informações de programacao automatizada
 */
struct agenda {
    uint8_t tipo;       //0 = Manual, 1 = Diario, 2 = Semanal, 3 = Automatico
    uint8_t valor1;     //Diario = Hora inicio, Semanal = Dia Semana
    uint8_t valor2;     //Diario = Minuto inicio, Semana = Hora Inicio
    uint8_t valor3;     //Diario = Hora Fim, Semanal = Minuto Inicio
    uint8_t valor4;     //Diario = Minuto Fim, Semanal = Tempo (Depende do dispositivo)

    /**
     * Verifica se a data hora está dentro da programação.
     */
    bool validar(struct ts *dataHora, bool tempoMinutos);

    private:
        uint32_t get_unixtime(struct ts *t);
};

void obterAgenda(struct agenda *agenda, uint8_t posicao);
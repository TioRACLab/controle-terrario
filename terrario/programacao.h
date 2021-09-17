/**
* Módulo de estrutura de programação dos processos
*
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>

#define PROG_ILUMINACAO 0
#define PROG_ESPECTRO 1
#define PROG_CASCATA 2
#define PROG_IRRIGACAO 3
#define PROG_NEBLINA 4

#define DOMINGO 1
#define SEGUNDA 2
#define TERCA 4
#define QUARTA 8
#define QUINTA 16
#define SEXTA 32
#define SABADO 64


/**
 * Informações de programacao automatizada
 */
struct programacao {
    uint8_t dias;           //Dias da semana da programação
    uint8_t horaInicio;     //Hora início da programação
    uint8_t minutoInicio;   //Minuto início da programação
    uint8_t horaFim;        //Hora fim da programação
    uint8_t minutoFim;      //Minuto fim da programação

    /**
     * Verifica se a data hora está dentro da programação.
     */
    bool validar(struct ts *dataHora, bool tempoMinutos);

    private:

        /**
         * Obtem o tempo em unix a partir de uma estrutura de datetime
         */
        //uint32_t get_unixtime(struct ts *t);

        /**
         * Valida se o dia atual é um dia da semana válido
         */
        bool validarDiaSemana(uint8_t diaSemana);
};

/**
 * Obtem a programação desejada
 */
void obterprogramacao(struct programacao *programacao, uint8_t posicao);
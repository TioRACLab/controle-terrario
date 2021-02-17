/**
* Header do módulo de configurador
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include <Arduino.h>
#include "terrarioCentral.h"
#include <LiquidCrystal_I2C.h>

#define STS_BOTAO_NULO 0
#define STS_BOTAO_ENTER 1
#define STS_BOTAO_ESQ 2
#define STS_BOTAO_DIR 4

#define pinoBotaoEnter 0
#define pinoBotaoEsq 0
#define pinoBotaoDir 0


class ConfiguradorApp {
    
public:
    ConfiguradorApp(LiquidCrystal_I2C *liquidCrystal);

    /**
     * Processo looping do configurador.
     * @return Quando verdadeiro, a aplicação de configuração está rodando.
     */
    bool loopConfigurador(struct ts *dataHora, uint16_t *status, uint16_t *statusManual);

private:
    uint8_t botaoAtual = 0; 
    uint8_t statusBotoes = 0; 
    uint8_t telaAtual = 0;

    LiquidCrystal_I2C *lcd;

    void validarBotao(uint8_t pino, uint8_t status);
};

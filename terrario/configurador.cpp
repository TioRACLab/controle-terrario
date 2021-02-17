/**
* Classe de configuração
* 
* Autor: Ricardo Augusto Coelho
* Site: https://tioraclab.com
* TioRACLAb
*/

#include "configurador.h"

ConfiguradorApp::ConfiguradorApp(LiquidCrystal_I2C *liquidCrystal) {
    lcd = liquidCrystal;
}

/**
 * Processo looping do configurador.
 * @return Quando verdadeiro, a aplicação de configuração está rodando.
 */
bool ConfiguradorApp::loopConfigurador(struct ts *dataHora, uint16_t *status, uint16_t *statusManual) {
    return telaAtual != 0;
}

void ConfiguradorApp::validarBotao(uint8_t pino, uint8_t status) {
    bool statusAtual = (statusBotoes & status) == status;

    if (digitalRead(pino)) {
        if (!statusAtual) {
            statusBotoes = statusBotoes | status;
            botaoAtual = status;
        }
    }
    else if (statusAtual) {
        statusBotoes = statusBotoes ^ status;
    }
}
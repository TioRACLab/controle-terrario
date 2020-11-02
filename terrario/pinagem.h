
//Constantes ou Defines
//Pinos que se comunicam com o módulo relê.
#define pinoLampada 9
#define pinoLampadaEspectro 8
#define pinoBombaPrincipal 7
#define pinoCachoeira 6
#define pinoIrrigacao 5
#define pinoReservatorio 4
#define pinoNeblina 3
#define pinoArcoIris 2


//Pinagens Sensores Hidráulicos
#define pinoSensorLago 21 //A7
#define pinoSensorReservatorio 20 //A6

//Pinos de controle do trenzinho.
#define pinoTrem1 12
#define pinoTrem2 11
#define pinoTremENA 10 //ENA

#define pinoBotao 13

//Status do Terrário

#define STS_DESLIGADO 0             //Tudo desligado.
#define STS_ILUMINACAO 1            //Luz de iluminação ligada.
#define STS_ESPECTRO 2              //Luz de espectro vermleho para as plantas ligadas.
#define STS_LAGO_MEDIO 4            //Nível do lago está no médio.
#define STS_LAGO_ALTO 8             //Nível do lago está alto.
#define STS_RESERVATORIO 16         //Nível do reservatório baixo.
#define STS_BOMBA_LAGO 32           //Bomba do lago ligada.
#define STS_BOMBA_RESERVATORIO 64   //Bomba do reservatório ligada.
#define STS_CACHOEIRA 128           //Válvula da cachoeira ligada.
#define STS_IRRIGACAO 256           //Válvula da irrigação ligada.
#define STS_NEBLINA 512             //Os nebolizadores estão ligados.
#define STS_ARCOIRIS 1024           //O arco íris está ligado.

#define STS_TREM_FRENTE 2048        //O trêm está andando para frente.
#define STS_TREM_REVERSO 4096       //O três está andando para trás.
#define STS_TREM_LENTO 8192         //Velocidade do trêm é lenta.
#define STS_TREM_MEDIO 16384        //Velocidade do trêm é mediana.
#define STS_TREM_RAPIDO 32768       //Velocidade do trêm é rápido.
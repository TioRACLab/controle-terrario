/*
Controle de irrigação!
https://github.com/TioRACLab/controle-terrario
*/

#include <config.h>
#include <Wire.h>
#include <ds3231.h>

const int pinoCascata = 8; 
const int pinoIrrigacao = 9; 
const int pinoLamapada = 10;

bool ativarIrrigacao = true;
struct ts t;

void setup() {
  pinMode(pinoCascata, OUTPUT);
  pinMode(pinoIrrigacao, OUTPUT);

  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_INTCN);
  
  t.hour=12; 
  t.min=30;
  t.sec=0;
  t.mday=07;
  t.mon=03;
  t.year=2020;
 
  DS3231_set(t); 
}

void loop() {

    delay(5000);
    mudarIrrigacao();

    /*DS3231_get(&t);

    Serial.print("Date : ");
    Serial.print(t.mday);
    Serial.print("/");
    Serial.print(t.mon);
    Serial.print("/");
    Serial.print(t.year);
    Serial.print("\t Hour : ");
    Serial.print(t.hour);
    Serial.print(":");
    Serial.print(t.min);
    Serial.print(".");
    Serial.println(t.sec);

    if (t.hour == 12 && t.min == 30 && t.sec == 30) {
        Serial.println("Ligou!!");
        mudarIrrigacao();

    }
    
    if (t.hour == 12 && t.min == 31&& t.sec == 0) {
        Serial.println("Desligou!!");
        mudarIrrigacao();
    }

    if (t.hour == 8 && t.min == 30 && t.sec == 0) {
        Serial.println("Ligou Lampada!!");
        mudarLampada(true);
    }

    if (t.hour == 20 && t.min == 30 && t.sec == 0) {
        Serial.println("Desligou Lampada!!");
        mudarLampada(false);
    }*/

    delay(1000);
}

void mudarIrrigacao() {
    ativarIrrigacao = !ativarIrrigacao;

    if (ativarIrrigacao) {
      digitalWrite(pinoCascata, HIGH);
      digitalWrite(pinoIrrigacao, HIGH);
    }
    else {
      digitalWrite(pinoCascata, LOW);
      digitalWrite(pinoIrrigacao, LOW); 
    }
}

void mudarLampada(bool ativar) {
    if (ativar) {
      digitalWrite(pinoLamapada, HIGH);
    }
    else {
      digitalWrite(pinoLamapada, LOW);
    }
}
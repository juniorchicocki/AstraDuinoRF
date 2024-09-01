#include <Arduino.h>

#include <RHReliableDatagram.h>                      // biblioteca Radiohead reliableDatagram
#include <RH_ASK.h>                                  // biblioteca Radiohead ASK
#include <SPI.h>                                     // biblioteca SPI

#define TX_ADDRESS 1                                 // endereço do transmissor
#define RX_ADDRESS 2                                 // endereço do recept
#define RF_PIN 13

#define RF_MULTIMEDIA 12
#define RF_SUBWOOFER 11
#define RF_CHROME 10
#define RF_ESQCIMA 9
#define RF_ESQBAIXO 8

#define RF_VOLCIMA 7
#define RF_VOLBAIXO 6
#define RF_PAUSE 5
#define RF_PROX 4
#define RF_ANT 3
#define RF_BT1 2
#define RF_BT2 15

RH_ASK driver(2000, RF_PIN);                         // instância RH ASK
RHReliableDatagram gerente(driver, TX_ADDRESS);      // configurando o gerenciador

uint8_t count = 1;                                   // contador
uint8_t data[] = "Mensagem de teste";                // mensagem a ser enviada
uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];                 // buffer da mensagem

void checkAndSend(int pin)
{
  if (digitalRead(pin) == HIGH) {
    char message[3];
    sprintf(message, "%d", pin);
    
    Serial.println(message);  // print na console serial
    gerente.sendtoWait((uint8_t *)message, strlen(message), RX_ADDRESS);  // envia a mensagem
  }
}

void setup()
{
  Serial.begin(9600);                                // inicializa console serial 9600 bps
  if (!gerente.init())                               // se a inicialização do gerenciador falhar
    Serial.println("Falha na inicializacao");        // print na console serial

  // Configura todos os pinos como entrada
  pinMode(RF_MULTIMEDIA, INPUT);
  pinMode(RF_SUBWOOFER, INPUT);
  pinMode(RF_CHROME, INPUT);
  pinMode(RF_ESQCIMA, INPUT);
  pinMode(RF_ESQBAIXO, INPUT);
  pinMode(RF_VOLCIMA, INPUT);
  pinMode(RF_VOLBAIXO, INPUT);
  pinMode(RF_PAUSE, INPUT);
  pinMode(RF_PROX, INPUT);
  pinMode(RF_ANT, INPUT);
  pinMode(RF_BT1, INPUT);
  pinMode(RF_BT2, INPUT);
}

void loop()
{
  // Verifica o estado de cada pino e envia o número do pino se estiver HIGH
  checkAndSend(RF_MULTIMEDIA);
  checkAndSend(RF_SUBWOOFER);
  checkAndSend(RF_CHROME);
  checkAndSend(RF_ESQCIMA);
  checkAndSend(RF_ESQBAIXO);
  checkAndSend(RF_VOLCIMA);
  checkAndSend(RF_VOLBAIXO);
  checkAndSend(RF_PAUSE);
  checkAndSend(RF_PROX);
  checkAndSend(RF_ANT);
  checkAndSend(RF_BT1);
  checkAndSend(RF_BT2);

  delay(500);                                               // atraso 0,5 segundo
}

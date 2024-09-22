#include <Arduino.h>
#include <VirtualWire.h>


#define RF_MULTIMEDIA 13
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
#define RF_BT2 14

void checkAndSend(int pin)
{
  if (digitalRead(pin) == HIGH)
  {
    char data[4];   
    itoa(pin, data,10);

    if (vw_send((uint8_t *)data, strlen(data)))
    {               
      vw_wait_tx(); 
      Serial.println("Enviado");
      Serial.println(data);
    }
    else
    {
      Serial.println("Falha no envio");
    }
  }
}

void setup()
{
  Serial.begin(9600);
  vw_set_tx_pin(12);
  vw_setup(2000);

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

  delay(500);
}

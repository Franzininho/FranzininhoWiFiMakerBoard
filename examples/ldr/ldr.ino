#include <Arduino.h>
#include "FranzininhoWiFiMakerBoard.h"

// Crie uma instância da classe FranzininhoWiFiMakerBoard
FranzininhoWiFiMakerBoard franzininho;

void setup() {
  // Inicialize a placa e configure os recursos
  Serial.begin(9600); // Inicialize a comunicação serial
}

void loop() {
  // Leia o valor do LDR
  int ldrValue = franzininho.readLDR();

  // Imprima o valor lido na porta serial
  Serial.print("Valor do LDR: ");
  Serial.println(ldrValue);

  // Aguarde um curto período antes de fazer a próxima leitura
  delay(1000); // Aguarde 1 segundo antes de fazer a próxima leitura
}

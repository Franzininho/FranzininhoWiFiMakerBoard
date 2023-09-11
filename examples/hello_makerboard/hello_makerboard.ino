#include <Arduino.h>
#include "FranzininhoWiFiMakerBoard.h"

// Crie uma instância da classe FranzininhoWiFiMakerBoard
FranzininhoWiFiMakerBoard franzininho;

void setup() {
  // Inicialize a placa e configure os recursos
  franzininho.setRGBColor(255, 0, 0); // Defina a cor do LED RGB para vermelho
  franzininho.playTone(500, 1000); // Reproduza um som no Buzzer por 1 segundo
  delay(1000);
  franzininho.playSiren();
}

void loop() {
  // Coloque aqui o código do loop principal, se necessário
}
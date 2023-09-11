#include <Arduino.h>
#include "FranzininhoWiFiMakerBoard.h"

// Crie uma instância da classe FranzininhoWiFiMakerBoard
FranzininhoWiFiMakerBoard franzininho;

// Variáveis para o estado dos botões
bool buttonAState = HIGH;
bool buttonBState = HIGH;

void setup() {
  // Inicialize a placa e configure os recursos
  franzininho.setRGBColor(0, 0, 255); // Cor inicial do LED: Azul

  // Inicialize a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura do estado do botão A
  bool newButtonAState = franzininho.readButtonA();

  // Verifica se o botão A foi pressionado
  if (newButtonAState == HIGH && buttonAState == LOW) {
    Serial.println("Botão A pressionado");
    franzininho.setRGBColor(255, 0, 0); // Cor vermelha quando o botão A é pressionado
  }
  // Verifica se o botão A foi solto
  else if (newButtonAState == LOW && buttonAState == HIGH) {
    Serial.println("Botão A solto");
    franzininho.setRGBColor(0, 0, 255); // Restaura a cor azul quando o botão A é solto
  }

  // Atualiza o estado do botão A
  buttonAState = newButtonAState;

  // Leitura do estado do botão B
  bool newButtonBState = franzininho.readButtonB();

  // Verifica se o botão B foi pressionado
  if (newButtonBState == HIGH && buttonBState == LOW) {
    Serial.println("Botão B pressionado");
    franzininho.setRGBColor(0, 255, 0); // Cor verde quando o botão B é pressionado
  }
  // Verifica se o botão B foi solto
  else if (newButtonBState == LOW && buttonBState == HIGH) {
    Serial.println("Botão B solto");
    franzininho.setRGBColor(0, 0, 255); // Restaura a cor azul quando o botão B é solto
  }

  // Atualiza o estado do botão B
  buttonBState = newButtonBState;
}

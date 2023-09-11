#include <Arduino.h>
#include "FranzininhoWiFiMakerBoard.h"

// Crie uma instância da classe FranzininhoWiFiMakerBoard
FranzininhoWiFiMakerBoard franzininho;

void setup() {
  // Inicialize a placa e configure os recursos
  franzininho.setRGBColor(255, 0, 0); // Inicie com a cor vermelha
}

void loop() {
  // Variáveis para as cores RGB
  int r = 255;
  int g = 0;
  int b = 0;

  // Loop para variar as cores gradualmente
  while (true) {
    // Aumentar a intensidade do verde e diminuir a do vermelho
    for (int i = 0; i <= 255; i++) {
      r--;
      g++;
      franzininho.setRGBColor(r, g, b);
      delay(10); // Pequeno atraso para suavizar a transição
    }

    // Aumentar a intensidade do azul e diminuir a do verde
    for (int i = 0; i <= 255; i++) {
      g--;
      b++;
      franzininho.setRGBColor(r, g, b);
      delay(10); // Pequeno atraso para suavizar a transição
    }

    // Aumentar a intensidade do vermelho e diminuir a do azul
    for (int i = 0; i <= 255; i++) {
      b--;
      r++;
      franzininho.setRGBColor(r, g, b);
      delay(10); // Pequeno atraso para suavizar a transição
    }
  }
}

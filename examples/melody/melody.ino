#include <Arduino.h>
#include "FranzininhoWiFiMakerBoard.h"

// Crie uma instância da classe FranzininhoWiFiMakerBoard
FranzininhoWiFiMakerBoard franzininho;

// Defina as frequências das notas musicais
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5
};

// Defina as durações das notas
int noteDurations[] = {
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

void setup() {
  // Inicialize a placa e configure os recursos
  franzininho.setRGBColor(255, 0, 0); // Cor vermelha para indicar que a música está tocando

  // Tocar a música "Parabéns pra Você"
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    franzininho.playTone(melody[i], noteDuration);

    // Pequeno atraso entre as notas
    delay(noteDuration * 1.30);
  }

  // Após tocar a música, pare o som e desligue o LED
  franzininho.stopTone();
  franzininho.turnOffRGB();

  // Aguarde um tempo antes de repetir
  delay(5000); // Espera 5 segundos antes de repetir
}

void loop() {
  
}

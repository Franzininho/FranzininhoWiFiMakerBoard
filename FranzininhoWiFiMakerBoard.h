#ifndef FRANZININHO_WIFI_MAKER_BOARD_H
#define FRANZININHO_WIFI_MAKER_BOARD_H

#include <Arduino.h>
#include <pitches.h>

class FranzininhoWiFiMakerBoard {
public:
    FranzininhoWiFiMakerBoard();

    // Funções para o LED RGB
    void setRGBColor(int r, int g, int b);
    void turnOffRGB();

    // Função para o Buzzer
    void playTone(int frequency, int duration);
    void playSiren();
    void stopTone();

    // Funções para as teclas
    bool readButtonA();
    bool readButtonB();

    // Funções para as entradas de touch resistivo
    int readTouch(int pin);

    // Funções para a matriz de LEDs
    void initializeMatrix();
    void setMatrixPixel(int x, int y, bool state);
    void updateMatrix();

    // Função para o LDR
    int readLDR();

private:
    // Defina os pinos correspondentes aos recursos da placa
    int rgbPins[3] = {40, 41, 42};
    int buzzerPin = 18;
    int buttonAPin = 34;
    int buttonBPin = 35;
    int touchPins[8] = {1, 2, 3, 4, 5, 6, 7, 11};
    int matrixPins[6] = {11, 12, 13, 14, 15, 16};
    int ldrPin = 9;

    // Outras variáveis e métodos necessários podem ser adicionados aqui
};

#endif

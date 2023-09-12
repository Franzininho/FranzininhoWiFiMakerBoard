#include "FranzininhoWiFiMakerBoard.h"

// Defina o tamanho do filtro de média móvel (ajuste conforme necessário)
const int numReadings = 10;

// Construtor
FranzininhoWiFiMakerBoard::FranzininhoWiFiMakerBoard() {
    // Inicialize os pinos e faça outras configurações necessárias aqui

    // Configurar os pinos do LED RGB como saída
    pinMode(rgbPins[0], OUTPUT); // Pino R
    pinMode(rgbPins[1], OUTPUT); // Pino G
    pinMode(rgbPins[2], OUTPUT); // Pino B

    // Configurar o pino do Buzzer como saída
    pinMode(buzzerPin, OUTPUT);

    // Configurar os pinos das teclas como entrada com pull-up
    pinMode(buttonAPin, INPUT_PULLUP);
    pinMode(buttonBPin, INPUT_PULLUP);

    //configura o pino do LDR como entrada
    pinMode(ldrPin, INPUT);

    // Configurar os pinos das entradas de touch resistivo como entrada
    for (int i = 0; i < 8; i++) {
        pinMode(touchPins[i], INPUT);
    }

    // Configurar os pinos da matriz de LEDs como saída
    for (int i = 0; i < 6; i++) {
        pinMode(matrixPins[i], OUTPUT);
    }
}

// Implemente os métodos definidos no arquivo .h

// Funções para o LED RGB
void FranzininhoWiFiMakerBoard::setRGBColor(int r, int g, int b) {
    // Certifique-se de que os valores de r, g e b estejam no intervalo de 0 a 255
    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);

    // Defina as cores do LED RGB usando PWM (0-255)
    analogWrite(rgbPins[0], r); // Vermelho
    analogWrite(rgbPins[1], g); // Verde
    analogWrite(rgbPins[2], b); // Azul
}

void FranzininhoWiFiMakerBoard::turnOffRGB() {
    // Desligue o LED RGB
    analogWrite(rgbPins[0], 0); // Vermelho
    analogWrite(rgbPins[1], 0); // Verde
    analogWrite(rgbPins[2], 0); // Azul
}

// Função para o Buzzer
void FranzininhoWiFiMakerBoard::playTone(int frequency, int duration) {
    tone(buzzerPin, frequency, duration);
}

// Método para reproduzir uma sirene
void FranzininhoWiFiMakerBoard::playSiren() {
    // Reproduza a sirene alternando rapidamente entre duas frequências
    for (int i = 0; i < 3; i++) {
        playTone(1000, 500); // Tocar uma frequência alta por 500 ms
        delay(250); // Pequeno atraso entre as frequências
        playTone(500, 500); // Tocar uma frequência mais baixa por 500 ms
        delay(250); // Pequeno atraso entre as frequências
    }
}

void FranzininhoWiFiMakerBoard::stopTone() {
    noTone(buzzerPin);
}

// Método para ler o botão A com debounce
bool FranzininhoWiFiMakerBoard::readButtonA() {
    static bool buttonAState = HIGH; // Estado atual do botão A
    static bool lastButtonAState = HIGH; // Estado anterior do botão A
    static unsigned long lastDebounceTime = 0; // Último momento em que ocorreu a mudança de estado
    const unsigned long debounceDelay = 50; // Tempo de debounce (ajuste conforme necessário)

    // Lê o estado atual do botão A
    bool buttonAReading = digitalRead(buttonAPin);

    // Verifica se houve uma mudança de estado
    if (buttonAReading != lastButtonAState) {
        lastDebounceTime = millis();
    }

    // Verifica se passou tempo suficiente desde a última mudança
    if ((millis() - lastDebounceTime) > debounceDelay) {
        // Atualiza o estado do botão A
        if (buttonAReading != buttonAState) {
            buttonAState = buttonAReading;
        }
    }

    // Atualiza o estado anterior do botão A
    lastButtonAState = buttonAReading;

    // Retorna o estado do botão A com debounce
    return buttonAState == LOW;
}

// Método para ler o botão B com debounce
bool FranzininhoWiFiMakerBoard::readButtonB() {
    static bool buttonBState = HIGH; // Estado atual do botão B
    static bool lastButtonBState = HIGH; // Estado anterior do botão B
    static unsigned long lastDebounceTime = 0; // Último momento em que ocorreu a mudança de estado
    const unsigned long debounceDelay = 50; // Tempo de debounce (ajuste conforme necessário)

    // Lê o estado atual do botão B
    bool buttonBReading = digitalRead(buttonBPin);

    // Verifica se houve uma mudança de estado
    if (buttonBReading != lastButtonBState) {
        lastDebounceTime = millis();
    }

    // Verifica se passou tempo suficiente desde a última mudança
    if ((millis() - lastDebounceTime) > debounceDelay) {
        // Atualiza o estado do botão B
        if (buttonBReading != buttonBState) {
            buttonBState = buttonBReading;
        }
    }

    // Atualiza o estado anterior do botão B
    lastButtonBState = buttonBReading;

    // Retorna o estado do botão B com debounce
    return buttonBState == LOW;
}

// Funções para as entradas de touch resistivo
int FranzininhoWiFiMakerBoard::readTouch(int pin) {
    // Implemente a lógica para ler as entradas de touch resistivo
}

// Funções para a matriz de LEDs
void FranzininhoWiFiMakerBoard::initializeMatrix() {
    // Implemente a lógica para inicializar a matriz de LEDs
}

void FranzininhoWiFiMakerBoard::setMatrixPixel(int x, int y, bool state) {
    // Implemente a lógica para definir o estado de um pixel na matriz de LEDs
}

void FranzininhoWiFiMakerBoard::updateMatrix() {
    // Implemente a lógica para atualizar a matriz de LEDs
}

// Função para o LDR
int FranzininhoWiFiMakerBoard::readLDR() {
    int ldrValue = analogRead(ldrPin);
    return ldrValue;
}

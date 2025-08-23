//  Mapeamento dos pinos

// INPUTS (Botões)
#define BTN_BLUE 7
#define BTN_GREY 10

// OUTPUTS (LEDs)
#define LED_GREEN 6
#define LED_YELLOW 4
#define LED_RED 2

void setup() {

  // Habilita comunicação serial
               // Baut rate ---> 9600 bits/s 
  Serial.begin(9600);

  // Configuração dos pinos de entrada
  pinMode(BTN_BLUE, INPUT);
  pinMode(BTN_GREY, INPUT);

  // Configuração de pinos de saída
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.println("Fim da inicialização - 2TDSPS");
  delay(1500);

}

void loop() {

  // Botão ON -> HIGH
  // Botão OFF -> LOW

  if (digitalRead(BTN_BLUE) == HIGH) {
    pisca();
  }

  bool statusBtn = digitalRead(BTN_GREY);

  if (statusBtn == HIGH) {
    Serial.println("DESLIGA ISSO OTO! DESLIGA!");
  }

}

void pisca() {

  // Fase 1
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(300);

  // Fase 2
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  delay(300);

}
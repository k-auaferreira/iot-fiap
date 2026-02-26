// Salvar (Ctrl + 5)
// Compilar / Verify (Ctrl + R) -> Salva e compila
// Carregar / Upload (Ctrl + U) -> Salva, compila e grava

#define LED 2 // LED azul onboard -> ligado ao pino 2 no DEVKIT V1

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  delay(500);
}

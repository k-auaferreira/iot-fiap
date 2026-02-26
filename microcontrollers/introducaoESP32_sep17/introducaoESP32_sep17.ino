#define LED 5
#define POT 34

// Variável para o ADC
int valor; // 0 a 4.095 ---> analogRead
int perc; // 0 a 100%

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);

  Serial.println("Fim da inicialização");
  Serial.println("");
}

void loop() {
  valor = analogRead(POT);
  delay(10); // 0.01 s
  perc = map(valor, 0, 4095, 0, 100);

  Serial.print("Valor ADC: " + String(valor));
  Serial.println(" - Percentual: " + String(perc) + "%");

  if(perc > 80) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW); 
}
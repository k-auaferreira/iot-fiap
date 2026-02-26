// Mapeamento de pinos de I/O
#define BT0 13

// Variável de contagem
int contador; // Já começa em zero

// Variáveis booleanas
boolean stBT0, flag0;

void setup() {

  Serial.begin(9600); // Habilita comunicação serial com baudrate de 9600 bits/s

  // Configuração do sentido dos pinos de I/o
  pinMode (BT0, INPUT_PULLUP);// Input habilitado com resistor interno

}

void loop() {
  
  stBT0 = digitalRead(BT0);
  delay(10); // 0.01s

  // Botão OFF -> HIGH (por conta do resistor INTERNO de PULLUP)
  // Botão ON 0 -> LOW

  // Detecção da borda de descida
  // Mudança de OFF para ON
  if(stBT0 == LOW && flag0 == LOW) {
    Serial.println("O botão passou de OFF para ON");
    flag0 = HIGH;
  }

  // Detecção da borda de subida
  // Mundaça de ON para OFF
  if (stBT0 == HIGH && flag0 == HIGH) {
    Serial.println("O botão passou de ON para OFF");
    flag0 = LOW;
    contador++;
  }

  if (stBT0 == LOW) {
    contador++;
    Serial.println(contador);
    delay(500) ;// 0.5s
  }

}
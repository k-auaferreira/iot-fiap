// Mapeamento de pinos

// LEDs
#define LED_AZUL 3
#define LED_VERM 4
#define LED_AMR 5
#define LED_VERD 6

// Botões
#define BT1 7
#define BT2 9
#define BT3 11
#define BT4 13

// Variáveis booleanas
boolean stBT1, flag1;
boolean stBT2;
boolean stBT3, flag3;
boolean stBT4;

// Variáveis int
int contador;

void setup() {

  Serial.begin(9600);

  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERM, OUTPUT);
  pinMode(LED_AMR, OUTPUT);
  pinMode(LED_VERD, OUTPUT);

  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  pinMode(BT3, INPUT_PULLUP);
  pinMode(BT4, INPUT);

}

void loop() {
  
  // ex10();
  // ex11();
  // ex12();
  // ex13();
  // ex14();

}

void ex10()  {

  stBT1 = digitalRead(BT1);
  stBT3 = digitalRead(BT3);
  delay(10);

  if (stBT1 == LOW) {
    digitalWrite(LED_AZUL, HIGH);
  };
  delay(500);

  if (stBT3 == LOW) {
    digitalWrite(LED_AZUL, LOW);
  };
  delay(500);

}

void ex11()  {

  stBT1 = digitalRead(BT1);
  delay(10);

  if (stBT1 == LOW) {
    contador++;
    delay(500);
    Serial.println(contador);

    if (contador == 10){
      contador = 0;
    };
  };

}

void ex12() {

  stBT1 = digitalRead(BT1);
  stBT3 = digitalRead(BT3);
  delay(10);

  if(stBT1 == LOW && flag1 == LOW) {
    Serial.println("Ligando contador...");
    flag1 = HIGH;
  }

  if (stBT1 == HIGH && flag1 == HIGH) {
    Serial.println("Parando contador...");
    flag1 = LOW;
  }

  if (flag1 == HIGH) {
    contador++;
    Serial.println(contador);
    delay(500);
  }

  if (stBT3 == LOW) {
    contador = 0;
    Serial.println("Contador zerado...");
    delay(500);
  }

}

void ex13() {

  ex12();

  if (contador == 4){
    digitalWrite(LED_VERD, HIGH);
  }
  if (contador == 8){
    digitalWrite(LED_AMR, HIGH);
  }
  if (contador == 12){
    digitalWrite(LED_VERM, HIGH);
  }
  if (contador == 20){
    contador = 0;
    digitalWrite(LED_VERD, LOW);
    digitalWrite(LED_AMR, LOW);
    digitalWrite(LED_VERM, LOW);
    Serial.println("Contador zerado...");
  }

}

void ex14() {

  stBT1 = digitalRead(BT1);
  stBT2 = digitalRead(BT2);
  stBT3 = digitalRead(BT3);
  delay(10);

  if(stBT1 == LOW && flag1 == LOW) {
    flag1 = HIGH;
  }

  if (stBT1 == HIGH && flag1 == HIGH) {
    flag1 = LOW;
  }

  if(stBT3 == LOW && flag3 == LOW) {
    flag3 = HIGH;
  }

  if (stBT3 == HIGH && flag3 == HIGH) {
    flag3 = LOW;
  }

  if (flag1 == HIGH && contador < 9) {
    contador++;
    Serial.println(contador);
    delay(500);

    if (contador == 9) {
      Serial.println("Limite máximo atingido");
    }
  }

  if (flag3 == HIGH && contador > 0) {
    contador--;
    Serial.println(contador);
    delay(500);

    if (contador == 0) {
      Serial.println("Limite mínimo atingido");
    }
  }

  if (stBT2 == LOW) {
    contador = 0;
    Serial.println("Contador zerado...");
    delay(500);
  }
}
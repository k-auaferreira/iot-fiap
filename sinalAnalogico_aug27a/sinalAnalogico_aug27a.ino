// Sinal analógico

/*

Variável que armazena o valor correspondente convertido pelo ADC
(Analog-To-Digital Converter)

O ADC Converter convente os valores de tensão em valores decimais de 10 bits

0.00 V ---> 0b0000000000 (direita) ---> 0
5.00 V ---> 0b1111111111 (esquerda) ---> 1.023

00 a 11 2 bits ---> 2 ^ 2 -> 4 ---> 0 a 3
000 a 111 3 bits ---> 2 ^ 3 -> 8 ---> 0 a 7
[...]

1024
2048
4096 ---> 0 4095

int x = analogRead(pino);
Pode ser 0(mínimo) ou 1023(máx)

*/

#define LED_AZ 3

// Variável que armazena o valor correspondente convertido pelo ADC
int valorAnalog;

void setup() {
  Serial.begin(9600);
  pinMode(LED_AZ, OUTPUT);

  /* 
    Obs.: Não é nessário a configuração
    dos pinos (pinMode) para sinais de
    entrada analógica.
  */
}

void loop() {
  valorAnalog = analogRead(A0);
  // 0 ---> 0.00V
  // 512 ---> +- 2.50V
  // 1023 ---> 5.00V
  delay(10); // 0,01 s

  Serial.println("Valor convertido pelo ADC: " + String(valorAnalog));
  delay(500);

  if(valorAnalog > 700){
    Serial.println("Limite atingido!!!");
    digitalWrite(LED_AZ, HIGH);
  } else {
    digitalWrite(LED_AZ, LOW);
  }

  delay(500); // 0.5s
}
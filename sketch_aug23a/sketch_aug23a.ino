/*

Linguagem Wiring -> C++

=====================================
Documentação: https://www.arduino.cc/
=====================================

PINOS DIGITAIS: 0 ao 13
(INPUT/OUTPUT ---> I/O)

I/O são sinais boolenos
0 | (LOW, FALSE, 0 V = nível baixo)
1 | (HIGH, TRUE, 5 V = nível alto)

Input (para mapear o sistema, captar informações):
  - Componentes
  - Temperatura
  - Detecção de objetos
  - Botões
  - Sensores digitais

Output (o que eu quero acionar):
  - Led
  - Aquecimento
  - Display

(TODOS OS PINOS PODEM SER INPUT OU OUTPUT)

Arduíno UNO -> roda a 16 MHz
T - 1 / 16.000.000 = 0.0000000625
T - 62.5ns

========================================
Usando IAs: Tomar cuidado com o hardware
========================================

*/

void setup() { // Vai rodar somente na inicialização ou no reset

  // Configuração do pino 13 como output
        //pino, função (pin, type)
  pinMode(13, OUTPUT);

  pinMode(5, OUTPUT);
  
  for (int i=0; i < 10; i++)
  {
    digitalWrite(3, HIGH);
    // delay (tempo | ms)
    delay(200);
    digitalWrite(3, LOW);
    delay(200);
  }

}

void loop() { // Vai rodar as instruções a cada 62.5ns

  // Ativar o LED
  digitalWrite(13, HIGH);
  // Função para atrasar
  delay(500); // Milissegundos

  // Desativar
  digitalWrite(13, LOW);
  // Função para atrasar
  delay(500); // Milissegundos

}
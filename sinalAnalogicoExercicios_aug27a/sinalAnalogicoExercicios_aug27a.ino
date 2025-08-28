#define LED_AZ 3
#define LED_VM 4
#define LED_AM 5
#define LED_VR 6

// Variável que armazena o valor correspondente convertido pelo ADC
int valorAnalog;
boolean flag01;
int limite_inf = 100;
int limite_sup = 950;

void setup() {
  Serial.begin(9600);
  pinMode(LED_AZ, OUTPUT);
  pinMode(LED_VM, OUTPUT);
  pinMode(LED_AM, OUTPUT);
  pinMode(LED_VR, OUTPUT);
}

void loop() {
  // ex3();
  // ex4();
}

void ex3() {
  valorAnalog = analogRead(A0);
  delay(10); 

  Serial.println("Valor convertido pelo ADC: " + String(valorAnalog));
  delay(500);

  if(valorAnalog < 200){
    digitalWrite(LED_AZ, HIGH);
  } else digitalWrite(LED_AZ, LOW);

  if(valorAnalog > 200 && valorAnalog < 650) {
    digitalWrite(LED_VM, HIGH);
  } else digitalWrite(LED_VM, LOW);

  if(valorAnalog > 650 && valorAnalog < 950) {
    digitalWrite(LED_AM, HIGH);
  } else digitalWrite(LED_AM, LOW);

  if(valorAnalog > 950 && valorAnalog < 1000) {
    digitalWrite(LED_VR, HIGH);
  } else digitalWrite(LED_VR, LOW);

  if(valorAnalog > 1000) {
    digitalWrite(LED_AZ, HIGH);
    digitalWrite(LED_VM, HIGH);
    digitalWrite(LED_AM, HIGH);
    digitalWrite(LED_VR, HIGH);
    flag01 = HIGH;
  }

  if (flag01 == HIGH){
    Serial.println("Alarme!!!");
    digitalWrite(LED_AZ, HIGH);
    digitalWrite(LED_VM, HIGH);
    digitalWrite(LED_AM, HIGH);
    digitalWrite(LED_VR, HIGH);
    delay(10);
    digitalWrite(LED_AZ, LOW);
    digitalWrite(LED_VM, LOW);
    digitalWrite(LED_AM, LOW);
    digitalWrite(LED_VR, LOW);
  }

  delay(500);
}

void ex4() {
  valorAnalog = analogRead(A0);
  delay(10);

  Serial.println("Valor convertido pelo ADC: " + String(valorAnalog));
  delay(500);

  if (valorAnalog > limite_sup) {
    digitalWrite(LED_AZ, HIGH);
    digitalWrite(LED_VM, HIGH);
    flag01 = HIGH;
  }

  if (valorAnalog < limite_inf){
    digitalWrite(LED_AZ, LOW);
    digitalWrite(LED_VM, LOW);
  }

  if (flag01 == HIGH && valorAnalog > limite_sup){
    digitalWrite(LED_AZ, HIGH);
    digitalWrite(LED_VM, HIGH);
    flag01 = LOW;
  }
}
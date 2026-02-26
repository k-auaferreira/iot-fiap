#include <DHT.h>

#define dhtPino 2
#define dhtTipo DHT22

DHT dht (dhtPino, dhtTipo);
float temperatura, umidade;

void setup() {
  dht.begin();
}

void loop() {

  // Graus Celsius
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  delay(2000);
  Serial.println("Temperatura: " + String(temperatura));
  Serial.println(F(" °C"));
  Serial.println("Umidade: " + String(umidade));
  Serial.println(" %");

  Serial.println("=====================================");
}
#include "DHT.h"

#define DHTPIN 7  
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

const int sensorPin = A0; 
float gas_value; 

const int AOUTpin=1;
const int DOUTpin=8;

int limit;
int value;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  pinMode(sensorPin, INPUT);

  pinMode(DOUTpin, INPUT);
  pinMode(AOUTpin, OUTPUT);
}

void loop() {
  delay(3000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  gas_value = analogRead(sensorPin); 
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
  
  Serial.print("Valoarea gasului = ");
  Serial.println(gas_value);

  if (gas_value < 200) {
    Serial.println("Aer curat / fara gaze detectabile.");
  } else if (gas_value >= 200 && gas_value < 400) {
    Serial.println("Posibil GPL (propan/butan) sau fum slab.");
  } else if (gas_value >= 400 && gas_value < 600) {
    Serial.println("Posibil metan sau alcool in aer.");
  } else if (gas_value >= 600 && gas_value < 800) {
    Serial.println("Concentratie mare de alcool sau fum.");
  } else if (gas_value >= 800) {
    Serial.println("Gaz dens detectat! Atentie!");
  }
  
  value= analogRead(AOUTpin);
  limit= digitalRead(DOUTpin);
  Serial.print("Alcohol value:  ");
  Serial.println(value);
  Serial.print("\n");

  Serial.println("-----------------------------------");
}

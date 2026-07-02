#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 7  
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

const int mq5Pin = A0;
const int mq3Pin = A1;  

float gas_value_MQ3; 
float gas_value_MQ5;

void setup() {
  Serial.begin(115200);

  dht.begin();
  pinMode(mq3Pin, INPUT);
  pinMode(mq5Pin, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop() {
  delay(3000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  gas_value_MQ3 = analogRead(mq3Pin); 
  gas_value_MQ5 = analogRead(mq5Pin);

  // Serial Monitor Output
  Serial.print(F("Humidity: "));
  Serial.print(h,2);
  Serial.print(F(" Temperature: "));
  Serial.print(t,2);
  Serial.print(F(" Valoare gaz MQ3: "));
  Serial.print(gas_value_MQ3,2);
  Serial.print(F(" Valoare gaz MQ5: "));
  Serial.print(gas_value_MQ5,2);
  Serial.println();
  
  /*
  if (gas_value_MQ5 < 200) {
    Serial.println("Aer curat / fara gaze detectabile.");
  } else if (gas_value_MQ5 >= 200 && gas_value_MQ5 < 400) {
    Serial.println("Posibil GPL (propan/butan) sau fum slab.");
  } else if (gas_value_MQ5 >= 400 && gas_value_MQ5 < 600) {
    Serial.println("Posibil metan sau alcool in aer.");
  } else if (gas_value_MQ5 >= 600 && gas_value_MQ5 < 800) {
    Serial.println("Concentratie mare de alcool sau fum.");
  } else if (gas_value_MQ5 >= 800) {
    Serial.println("Gaz dens detectat! Atentie!");
  }
  Serial.println("-----------------------------------");
  */

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print(t, 1);
  display.print("C");

  display.setCursor(64, 0);
  display.print(h, 0);
  display.print("%");

  display.setCursor(0, 24);
  display.print("MQ3:");

  display.setCursor(0, 40);
  display.print(gas_value_MQ3, 0);

  display.setCursor(64, 24);
  display.print("MQ5:");

  display.setCursor(64, 40);
  display.print(gas_value_MQ5, 0);

  display.display();

}

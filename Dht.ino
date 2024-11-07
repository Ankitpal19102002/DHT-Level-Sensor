#include <DHT.h>

#define DHTPIN 15          // Use A1 as a digital pin by referencing it as pin 15
#define DHTTYPE DHT11      // Change to DHT22 if you're using that sensor

#define LED_PIN 4          // Define pin for the extra LED

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Testing DHT sensor...");
  dht.begin();

  // Initialize the LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // Turn the LED on
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  Serial.println("IR Signal Transmitting...."); // Print an empty line for better readability
  delay(2000);      // Update every 2 seconds
}

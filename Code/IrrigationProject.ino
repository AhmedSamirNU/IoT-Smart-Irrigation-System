

#define BLYNK_TEMPLATE_ID "TMPL2UpJEvX8f" 

#define BLYNK_TEMPLATE_NAME "Smart Irrigation" 

#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#define BLYNK_PRINT Serial  

#include <WiFi.h> 

#include <WiFiClient.h> 

#include <BlynkSimpleEsp32.h> 

#include "DHT.h" 

char ssid[] = "YOUR_WIFI_NAME";

char pass[] = "YOUR_WIFI_PASSWORD";   

#define DHTPIN 4 

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); 

#define SOIL_PIN 34 

#define LDR_PIN 35 

#define FLAME_PIN 27 

#define WATER_PIN 32 





#define BUZZER_PIN 25 

#define TRIG_PIN 13 

#define ECHO_PIN 14 

long duration; 

float distance; 

BlynkTimer timer; 

void sendSensorData() { 

float temp = dht.readTemperature(); 

float hum = dht.readHumidity(); 

int flameState = digitalRead(FLAME_PIN); 

int rawSoil = analogRead(SOIL_PIN); 

int soilPercentage = map(rawSoil, 4095, 1000, 0, 100); 

soilPercentage = constrain(soilPercentage, 0, 100);  

int rawLight = analogRead(LDR_PIN); 

int lightPercentage = map(rawLight, 4095, 0, 0, 100); 

lightPercentage = constrain(lightPercentage, 0, 100); 

int waterValue = analogRead(WATER_PIN);  

digitalWrite(TRIG_PIN, LOW); 

delayMicroseconds(2); 

digitalWrite(TRIG_PIN, HIGH); 

 

  delayMicroseconds(10); 

  digitalWrite(TRIG_PIN, LOW); 

  duration = pulseIn(ECHO_PIN, HIGH); 

  distance = duration * 0.034 / 2; 

 

  // ====================================================== 

  // SERIAL MONITOR OUTPUT 

  // ====================================================== 

  Serial.println("==============="); 

   

  Serial.print("Temperature: "); Serial.print(temp); Serial.print(" C -> "); 

  if (temp < 15) Serial.println("(LOW  )"); 

  else if (temp <= 35) Serial.println("(GOOD     )"); 

  else Serial.println("(HIGH   )"); 

 

  Serial.print("Humidity: "); Serial.print(hum); Serial.print(" % -> "); 

  if (hum < 30) Serial.println("(LOW/Dry                  )"); 

  else if (hum <= 70) Serial.println("(GOOD  )"); 

  else Serial.println("(HIGH       )"); 

 

  Serial.print("Soil Moisture: "); Serial.print(soilPercentage); Serial.print(" % -> "); 

  if (soilPercentage < 30) Serial.println("(LOW - Needs Water     )"); 

  else if (soilPercentage <= 70) Serial.println("(GOOD   )"); 

  else Serial.println("(HIGH - Too Wet        )"); 

 

  Serial.print("Light Level: "); Serial.print(lightPercentage); Serial.print(" % -> "); 

  if (lightPercentage < 20) Serial.println("(DARK   )"); 

  else if (lightPercentage <= 70) Serial.println("(GOOD     )"); 

 

  else Serial.println("(BRIGHT   )"); 

  Serial.print("Rain Detected: "); 

  if (waterValue > 3900) {  

    Serial.println("YES      ");  

  } else { 

    Serial.println("NO   "); 

  } 

  Serial.print("Tank Distance: "); Serial.print(distance); Serial.print(" cm -> "); 

  if (distance > 7) Serial.println("(LOW - Needs Refill    )"); 

  else if (distance >= 3) Serial.println("(GOOD   )"); 

  else Serial.println("(FULL   )"); 

 

  Serial.print("Flame Detected: "); 

  if (flameState == LOW) {  

    Serial.println("YES - FIRE DETECTED   "); 

    digitalWrite(BUZZER_PIN, HIGH); 

  } else { 

    Serial.println("NO"); 

    digitalWrite(BUZZER_PIN, LOW); 

  } 

 

  Serial.println();  

  Blynk.virtualWrite(V0, temp); 

  Blynk.virtualWrite(V1, hum); 

  Blynk.virtualWrite(V2, soilPercentage);  

  Blynk.virtualWrite(V3, lightPercentage);  

  Blynk.virtualWrite(V4, waterValue);  

  Blynk.virtualWrite(V5, distance); 

 



  Blynk.virtualWrite(V6, flameState == LOW ? 1 : 0);  

} 

void setup() { 

  Serial.begin(115200); 

  delay(1000); 

 

  Serial.println("\n======================="); 

  Serial.println("BOOTING SYSTEM..."); 

  Serial.println("======================="); 

 

  dht.begin(); 

   

  pinMode(FLAME_PIN, INPUT_PULLUP);  

   

  pinMode(BUZZER_PIN, OUTPUT); 

  pinMode(TRIG_PIN, OUTPUT); 

  pinMode(ECHO_PIN, INPUT); 

  digitalWrite(BUZZER_PIN, LOW); 

 

  Serial.println("Connecting to WiFi and Blynk..."); 

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 

  Serial.println("SYSTEM ONLINE!"); 

 

  timer.setInterval(2000L, sendSensorData); 

} 

void loop() { 

  Blynk.run(); 

  timer.run();